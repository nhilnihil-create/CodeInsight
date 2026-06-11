#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
int main()
{
    string s;
    cin >> s;
    ll n = s.length();

    vector<ll> v;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == 'W')
            v.push_back(i + 1);
    }

    ll k = (v.size() * (v.size() + 1)) / 2;
    for (ll i = 0; i < v.size(); i++)
        k = k - v[i];

    cout << -1 * k << "\n";

    return (0);
}
