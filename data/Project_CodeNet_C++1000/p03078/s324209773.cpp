#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <tuple>
#include <algorithm>

constexpr int MAX = 1010;

using ll = long long int;
using T = std::tuple<ll, int, int, int>;

ll a[MAX], b[MAX], c[MAX];

std::set<T> used;
std::priority_queue<T> que;

int dx[] = {1, 0, 0}, dy[] = {0, 1, 0}, dz[] = {0, 0, 1};

int main()
{

    int x, y, z, k;

    std::cin >> x >> y >> z >> k;

    for (int i = 0; i < x; ++i)
        std::cin >> a[i];
    for (int i = 0; i < y; ++i)
        std::cin >> b[i];
    for (int i = 0; i < z; ++i)
        std::cin >> c[i];

    std::sort(a, a + x, std::greater<>());
    std::sort(b, b + y, std::greater<>());
    std::sort(c, c + z, std::greater<>());

    que.emplace(a[0] + b[0] + c[0], 0, 0, 0);

    for (int i = 0; i < k; ++i)
    {
        int X, Y, Z;
        ll t;
        std::tie(t, X, Y, Z) = que.top();
        que.pop();
        std::cout << t << std::endl;

        for (int j = 0; j < 3; ++j)
        {
            int xx = X + dx[j], yy = Y + dy[j], zz = Z + dz[j];
            if (xx == x || yy == y || zz == z)
                continue;
            ll tt = a[xx] + b[yy] + c[zz];
            if (used.count(T(tt, xx, yy, zz)))
                continue;
            que.emplace(tt, xx, yy, zz);
            used.emplace(tt, xx, yy, zz);
        }
    }

    return 0;
}