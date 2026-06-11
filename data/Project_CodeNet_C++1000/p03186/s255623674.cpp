#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    long long a, b, c, ans = 0;
    std::cin >> a >> b >> c;
    ans += b;
    long long dokukeshi = a + b;
    
    while (c != 0 && dokukeshi != 0)
    {
        --c;
        --dokukeshi;
        ++ans;
    }
    
    if (c != 0) { ++ans; }
    std::cout << ans << std::endl;

    return 0;
}
