#include <bits/stdc++.h>


int main() {
    const int valueOfCoin = 500;
    int payment = 0;
    int numOf1yen = 0;
    std::cin >> payment >> numOf1yen;
    
    int fraction = payment % valueOfCoin;
    if(fraction <= numOf1yen) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }    
}