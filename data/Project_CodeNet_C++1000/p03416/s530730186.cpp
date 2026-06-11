#include <iostream>
#include <string>

bool isPalindromicNumber(std::string number);

int main() {
    int lowerNumber = 0;
    int upperNumber = 0;
    std::cin >> lowerNumber >> upperNumber;
    int numOfPalindromicNumbers = 0;
    for (int i = lowerNumber; i <= upperNumber; i++) {
        if (isPalindromicNumber(std::to_string(i))) {
            numOfPalindromicNumbers++;
        }
    }
    
    std::cout << numOfPalindromicNumbers << std::endl;
}
    
bool isPalindromicNumber(std::string number) {
    bool isPalindromic = true;
    size_t numOfDigit = number.length();
    for (size_t i = 0U; i < numOfDigit / 2U; i++) {
        if (number.at(i) != number.at(numOfDigit - 1 - i)) {
            isPalindromic = false;
            break;
        }
    }
    return isPalindromic;
}