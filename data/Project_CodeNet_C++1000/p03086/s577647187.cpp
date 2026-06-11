#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

ll MOD = 1000000007;

ll m;
string s;

int solve(ll n)
{
    ll count = 0;
    for (ll i = n; i < m; i++)
    {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

int main()
{

    cin >> s;

    m = s.size();

    ll ans = 0, tmp = 0;

    for (ll i = 0; i <= m; i++)
    {
        tmp = solve(i);
        if (tmp > ans)
        {
            ans = tmp;
        }
    }

    cout << ans << endl;
}
