#include <iostream>
#include <map>
#include <string>
constexpr int MOD = 1'000'000'007;
int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::map<char, int> mp;
    for (const char c : s)
        ++mp[c];
    long long ans = 1;
    for (const auto e : mp) {
        ans *= (e.second + 1);
        ans %= MOD;
    }
    ans += (MOD - 1);
    ans %= MOD;
    std::cout << ans << '\n';
}