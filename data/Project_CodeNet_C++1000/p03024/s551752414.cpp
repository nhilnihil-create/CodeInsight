#include <iostream>

int main() {
    std::string s;
    int n = 15, k, wins = 0;

    std::cin >> s;
    k = s.size();
    for (char c : s) wins = (c == 'o') ? wins + 1 : wins;

    std::cout << ( (n - k >= 8 - wins) ? "YES" : "NO" ) << std::endl;

    return 0;
}

