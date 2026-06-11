#include <iostream>

bool isBuyable(int price, int moneyInHand);

int main() {
    int price = 0;
    int numOfOneYen = 0;
    std::cin >> price >> numOfOneYen;
    static const int INFINITE_COIN_YEN = 500; 
    
    int lastPrice = price % INFINITE_COIN_YEN;
    if (isBuyable(lastPrice, numOfOneYen)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
 
bool isBuyable(int price, int moneyInHand) {
    return moneyInHand >= price;
}