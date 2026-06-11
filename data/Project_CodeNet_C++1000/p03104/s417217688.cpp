#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    ll n = b - a + 1;
    if (a % 2)
    {
        ans = a;
        n--;
    }
    if (n % 2 == 0)
    {
        if ((n / 2) % 2 == 0)
        {
            ans = ans ^ 0;
        }
        else
        {
            ans = ans ^ 1;
        }
    }
    else
    {
        n--;
        if ((n / 2) % 2 == 0)
        {
            ans = ans ^ 0;
            ans = ans ^ b;
        }
        else
        {
            ans = ans ^ 1;
            ans = ans ^ b;
        }
    }
    cout << ans << endl;
}