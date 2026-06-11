#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    long long a, b;
    int k;
    std::cin >> a >> b >> k;
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            if (a % 2 != 0) { a--; }
            a -= (a / 2);
            b += a;
        }
        else
        {
            if (b % 2 != 0) { b--; }
            b -= (b / 2);
            a += b;
        }
    }

    std::cout << a << ' ' << b << std::endl;
    return 0;
}