#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

int main() {
    int n;
    auto ret = 0ll;
    std::string s;
    std::cin >> n >> s;
    std::string l(s.substr(0, n)), r(s.substr(n, n));
    std::reverse(r.begin(), r.end());
    std::map<std::pair<std::string, std::string>, long long> ml, mr;

    for (auto i = 0ll, limit = (1ll << n); i < limit; i++) {
        std::string sublr, sublb, subrb, subrr;
        for (auto d = 0; d < n; d++) {
            if ((1ll << d) & i) sublr += l[d], subrr += r[d];
            else sublb += l[d], subrb += r[d];
        }
        std::reverse(sublb.begin(), sublb.end());
        std::reverse(subrb.begin(), subrb.end());
        ml[std::make_pair(sublr, sublb)]++;
        mr[std::make_pair(subrr, subrb)]++;
    }

    for (auto& el : ml) {
        ret += el.second * mr[el.first];
    }

    std::cout << ret << std::endl;

    return 0;
}