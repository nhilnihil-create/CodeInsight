#include <iostream>

int divisors(int n) {
    int res = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ++res;
            if (n / i != i) ++res;
        }
    }
    return res;
}

int main() {
    int n, c=0;
    std::cin >> n;
    for (int i = 1; i <= n; i+=2) {
        if(divisors(i)==8) c++;
    }
    std::cout << c << '\n';
    return 0;
}