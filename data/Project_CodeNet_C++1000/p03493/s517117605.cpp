#include <bits/stdc++.h>


int main() {
    std::string squares;
    std::cin >> squares;
    
    int numOfMarble = 0;
    for(unsigned long i = 0; i < squares.length(); ++i) {
        if(squares.at(i) == '1') {
            ++numOfMarble;
        }
    }
    std::cout << numOfMarble << std::endl;
}