// ABC 100 A: happy birthday
#include <iostream>
#include <algorithm>

int main() {
    bool flag = true;
    int cake_num_1, cake_num_2; std::cin >> cake_num_1 >> cake_num_2;
    if (cake_num_1 < cake_num_2) {
        int tmp = cake_num_1;
        cake_num_1 = cake_num_2;
        cake_num_2 = tmp;
    }
    if (cake_num_1 > 16/2) {
        flag = false;
    }
    std::cout << (flag ? "Yay!" : ":(") << "\n"; 

}