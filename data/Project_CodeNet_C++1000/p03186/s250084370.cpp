#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    long long a, b, c, ans = 0;
    std::cin >> a >> b >> c;
    if (a + b + 1 >= c) { ans = b + c; }
    else
    {
        ans = b + (a + b + 1);
    }
    std::cout << ans << std::endl;

    return 0;
}
