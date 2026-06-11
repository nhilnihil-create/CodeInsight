#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string s1 = s.substr(0, n), s2 = s.substr(n);
    std::vector<std::pair<std::string, std::string>> v1(1 << n), v2(1 << n);
    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) (i & (1 << j) ? v1[i].first : v1[i].second) += s1[j];
    }
    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) (i & (1 << j) ? v2[i].first : v2[i].second) += s2[j];
        std::reverse(v2[i].first.begin(), v2[i].first.end());
        std::reverse(v2[i].second.begin(), v2[i].second.end());
    }
    std::sort(v2.begin(), v2.end());
    long long ans = 0;
    for (auto vv : v1) {
        auto p = std::make_pair(vv.second, vv.first);
        ans += std::upper_bound(v2.begin(), v2.end(), p) - std::lower_bound(v2.begin(), v2.end(), p);
    }
    std::cout << ans << std::endl;
}
