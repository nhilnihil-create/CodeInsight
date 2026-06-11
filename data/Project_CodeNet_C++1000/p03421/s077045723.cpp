#include <iostream>
#include <algorithm>

#define int long long int

main()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    if (n < a + b - 1 || n > a * b * 1LL)
    {
        std::cout << -1;
    }
    else
    {
        for (int i = a - 1; i >= 0; --i)
        {
            std::cout << n - i << " ";
        }

        n -= a;
        int temp = b;
        --b;
        for (int i = 1; i < temp; ++i)
        {
            int cur = n - b + 1;
            cur = std::min(cur, a);

            for (int j = cur - 1; j >= 0; --j)
            {
                std::cout << n - j << " ";
            }

            n -= cur;
            --b;
        }
    }
}
