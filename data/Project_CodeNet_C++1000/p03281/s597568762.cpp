#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

ll MOD = 1000000007;

int solve(ll n)
{
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;

        if (count == 9)
        {
            return count;
        }
    }

    return count;
}

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;

    for (ll i = 1; i <= n; i += 2)
    {
        if (solve(i) == 8)
        {
            ans++;
        }
    }

    cout << ans << endl;
}
