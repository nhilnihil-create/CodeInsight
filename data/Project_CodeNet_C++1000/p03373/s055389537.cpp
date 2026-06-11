#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int a, b, c, x, y;
    int ans = 0;

    cin >> a >> b >> c >> x >> y;

    if (x > y)
    {
        if (a + b > 2 * c)
        {
            ans = ans + c * 2 * y;
        }
        else
        {
            ans = ans + a * y + b * y;
        }

        if ((x - y) * a < (x - y) * 2 * c)
        {
            ans += (x - y) * a;
        }
        else
        {
            ans += (x - y) * 2 * c;
        }
    }
    else if (x <= y)
    {
        if (a + b > 2 * c)
        {
            ans = ans + c * 2 * x;
        }
        else
        {
            ans = ans + a * x + b * x;
        }

        if ((y-x) * b < (y-x) * 2 * c)
        {
            ans += (y-x) * b;
        }
        else
        {
            ans += (y-x) * 2 * c;
        }
    }

    cout << ans << endl;

    return 0;
}