//工厂模式-工厂方法模式

//特点：定义一个创建对象的接口，其子类去具体现实这个接口以完成具体的创建工作。如果需要增加新的产品类，只需要扩展一个相应的工厂类即可。
//缺点：产品类数据较多时，需要实现大量的工厂类，这无疑增加了代码量。

#include <iostream>

enum tank_type {
    tank_64,
    tank_96
};

class Tank
{
public:
    virtual void print_tank() = 0;
};

class Tank_64 :public Tank
{
public:
    void print_tank() {
        std::cout << "tank_64" << std::endl;
    }
};

class Tank_96 :public Tank
{
public:
    void print_tank() {
        std::cout << "tank_96" << std::endl;
    }
};

class Tankfactory {
public:
    virtual std::unique_ptr<Tank> createTank() = 0;
};

class Tank64factory : public Tankfactory {
    std::unique_ptr<Tank> createTank() {
        return std::make_unique<Tank_64>();
    }
};

class Tank96factory : public Tankfactory {
    std::unique_ptr<Tank> createTank() {
        return std::make_unique<Tank_96>();
    }
};

int main()
{
    std::unique_ptr<Tankfactory> tankfactory1 = std::make_unique<Tank64factory>();
    auto tank1 = tankfactory1->createTank();
    tank1->print_tank();

    std::unique_ptr<Tankfactory> tankfactory2 = std::make_unique<Tank96factory>();
    auto tank2 = tankfactory2->createTank();
    tank2->print_tank();
}
