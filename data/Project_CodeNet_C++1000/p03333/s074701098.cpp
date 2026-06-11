#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

#define int long long int

bool compare(const int &a, const int &b)
{
    return a > b;
}

main()
{
    int n;
    std::cin >> n;

    int x[100010], y[100010];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i] >> y[i];
    }
    x[n] = 0;
    y[n] = 0;

    std::sort(x, x + n + 1, compare);
    std::sort(y, y + n + 1);

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (x[i] > y[i])
            ans += 2 * (x[i] - y[i]);
    }

    std::cout << ans;
}
