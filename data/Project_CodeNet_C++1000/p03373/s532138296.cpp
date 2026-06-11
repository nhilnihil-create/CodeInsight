#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;

    if (A + B < 2 * C)
        ans = A * X + B * Y;
    else
    {
        if (X >= Y)
        {
            ans += 2 *C * Y;
            if (A <= 2 * C)
            {
                ans += A * (X - Y);
            }
            else
            {
                ans += C * (X - Y) * 2;
            }
        }
        else
        {
            ans += 2 * C * X;
            if (B <= 2 * C)
            {
                ans += B * (Y - X);
            }
            else
            {
                ans += C * (Y - X) * 2;
            }
        }
    }

    cout << ans << endl;

    return 0;
}