#include <bits/stdc++.h>


int main() {
    unsigned int numOfHinaArare;
    std::cin >> numOfHinaArare;
    
    std::string bagOfHinaArare;
    char hinaArare;
    for(unsigned int i = 0U; i < numOfHinaArare; ++i) {
        std::cin >> hinaArare;
        bagOfHinaArare += hinaArare;
    }
    
    bool isYellowExist = false;
    for(char collerOfHinaArare : bagOfHinaArare) {
        if(collerOfHinaArare == 'Y') {
            isYellowExist = true;
            break;
        }
    }
    
    if(isYellowExist) {
        std::cout << "Four" << std::endl;
    } else {
        std::cout << "Three" << std::endl;
    }    
}