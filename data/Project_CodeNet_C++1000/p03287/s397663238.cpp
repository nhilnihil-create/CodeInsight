#include <iostream>
#include <map>

using ll = long long int;

constexpr int MAX = 1e5 + 10;

std::map<int, ll> map;

int main()
{

    int n, m;

    std::cin >> n >> m;

    int mod = 0;

    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        mod = (mod + a) % m;
        ++map[mod];
    }

    ll ans = 0;

    for (auto p : map)
    {

        ans += p.second * (p.second - 1) / 2;
    }

    std::cout << ans + map[0] << std::endl;

    return 0;
}