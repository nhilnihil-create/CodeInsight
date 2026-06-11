#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rag(con) std::begin(con), std::end(con)

int main()
{
    int m, k;

    std::cin >> m >> k;

    int x = 1;

    rep(i, m)
        x *= 2;

    if (k >= x)
        std::cout << -1 << std::endl;
    else if (m == 1)
    {
        if (k == 0)
            std::cout << "0 0 1 1" << std::endl;
        else
        {
            std::cout << -1 << std::endl;
        }
    }
    else
    {
        rep(i, x)
        {
            if (i != k)
                std::cout << i << ' ';
        }
        std::cout << k << ' ';
        for (int i = x - 1; i >= 0; --i)
        {
            if (i != k)
                std::cout << i << ' ';
        }
        std::cout << k << ' ' << std::endl;
    }

    return 0;
}