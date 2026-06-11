#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
        return a;
    ll r = a % b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> leftacc(n + 1);
    vector<ll> rightacc(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (0 == i)
        {
            leftacc[i + 1] = a[i];
            continue;
        }

        leftacc[i + 1] = gcd(leftacc[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (n - 1 == i)
        {
            rightacc[i] = a[i];
            continue;
        }

        rightacc[i] = gcd(rightacc[i + 1], a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, gcd(leftacc[i], rightacc[i + 1]));
    }
    cout << ans << endl;
    return 0;
}