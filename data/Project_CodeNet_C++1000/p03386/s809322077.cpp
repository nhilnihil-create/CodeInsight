#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int main() {
    long long a, b;
    long long k;
    std::cin >> a >> b >> k;

    if(a + k - 1 <= b - k + 1) {
        for (long long i = a; i <= b; i++) {
            if(i >= a && i <= a + k - 1 || i <= b && i > b - k) {
                std::cout << i << "\n";
            }
        }
    } else {
        for (long long i = a; i <= b; i++) {
            std::cout << i << "\n";
        }
    }
}