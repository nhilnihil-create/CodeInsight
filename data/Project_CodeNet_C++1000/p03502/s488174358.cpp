#include <iostream>
#include <string>
#include <vector>

int main () {
    int n;
    std::cin >> n;
    int x = n;
    int f = 0;
    while(n > 0) {
        f += n % 10;
        n /= 10;
    }

    std::string ans = (x % f == 0) ? "Yes" : "No";
    std::cout << ans << "\n";
}