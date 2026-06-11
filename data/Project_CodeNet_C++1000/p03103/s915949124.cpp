#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    ll ans = 0, ind = 0;
    while (m)
    {
        int amt = min(m, v[ind].second);
        m -= amt;
        v[ind].second -= amt;
        ans += amt * v[ind].first;
        if (!v[ind].second) ind++;
    }

    cout << ans << "\n";
}