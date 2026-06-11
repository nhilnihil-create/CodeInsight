#include <iostream>
#include <string>
int main() {
    std::string s;
    std::cin >> s;
    long long ans = 0;
    int cnt = 0;
    for (const auto c : s) {
        if (c == 'B')
            ++cnt;
        else
            ans += cnt;
    }
    std::cout << ans << '\n';
}