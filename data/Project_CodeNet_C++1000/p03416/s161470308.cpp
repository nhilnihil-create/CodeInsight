#include <bits/stdc++.h>


unsigned int numberReverse(unsigned int forwardNumber) {
    unsigned int reverseNumber = 0U;
    
    while(forwardNumber != 0U) {
        reverseNumber = forwardNumber % 10 + reverseNumber * 10;
        forwardNumber /= 10;
    }
    return reverseNumber;
}  

int main() {
    unsigned int firstNumber;
    unsigned int lastNumber;
    std::cin >> firstNumber >> lastNumber;
    
    unsigned int numOfPalindrome = 0U;
    for(unsigned int i = firstNumber; i <= lastNumber; ++i) {
        unsigned int reverseNumber = numberReverse(i);
        if(i == reverseNumber) {
            ++numOfPalindrome;
        }
    }
    std::cout << numOfPalindrome << std::endl;
}
