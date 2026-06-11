#include <iostream>

int main(int argc, char **argv)
{
    int N, A, B;
    std::cin >> N >> A >> B;

    if((A - B) % 2 == 0){
        std::cout << "Alice" << std::endl;
    }else{
        std::cout << "Borys" << std::endl;
    }
}
