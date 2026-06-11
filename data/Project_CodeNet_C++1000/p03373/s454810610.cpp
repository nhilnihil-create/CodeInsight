#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = A * X + B * Y;
    for (int i = 1; i <= max(X, Y); i++)
    {
        if (i <= min(X, Y))
        {
            ans = min(ans, ans - A - B + 2 * C);
        }
        else
        {
            if (X > Y)
            {
                ans = min(ans, ans - A + 2 * C);
            }
            else
            {
                ans = min(ans, ans - B + 2 * C);
            }
        }
    }
    cout << ans << endl;

    return 0;
}