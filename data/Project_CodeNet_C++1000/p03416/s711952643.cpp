#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> digits(long n);
bool isPalindrome(std::vector<int> digits);

int main() {
    long a, b, p = 0;
    std::cin >> a >> b;

    while(a <= b) {
        if(isPalindrome(digits(a))) {
            ++p;
        }

        ++a;
    }

    std::cout << p << "\n";
}

// ------------------------------------------------------- //
std::vector<int> digits(long n) {
    std::vector<int> vec;

    while(n > 0) {
        vec.push_back(n % 10);
        n /= 10;
    }

    return vec;
}

bool isPalindrome(std::vector<int> digits) {
    int i = 0;
    int j = digits.size()-1;

    while(i < j) {
        if(digits[i] != digits[j]) {
            return false;
        }

        ++i;
        --j;
    }

    return true;
}