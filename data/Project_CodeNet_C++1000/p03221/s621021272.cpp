#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using ll = long long;
using lli = long long int;

ll n, m, p, y;
std::map<ll, std::vector<ll>> ma;
std::map<ll, std::map<ll, ll>> m2;
std::vector<std::pair<ll, ll>> inputs;

int main() {
    std::cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        std::cin >> p >> y;
        ma[p].push_back(y);
        inputs.push_back(std::make_pair(p, y));
    }
    for (auto &x: ma) {
        std::sort(x.second.begin(), x.second.end());
        ll c = 1;
        for (ll i = 0; i < x.second.size(); i++) {
            m2[x.first][x.second[i]] = c;
            c++;
        }
    }
    for (auto &v: inputs) {
        ll create_num = m2[v.first][v.second];
        std::printf("%06d%06d\n", v.first, create_num);
    }
}
