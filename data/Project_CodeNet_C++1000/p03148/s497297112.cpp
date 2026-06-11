#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 1e18
int main()
{
    ll n, i, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    ll a[n + 2], b[n + 2];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        v.push_back({b[i], a[i]});
    }
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    ll num = 0;
    ll sum = 0;
    vector<ll> x, y;
    map<ll, ll> mp;
    for (i = 0; i < k; i++)
    {
        if (mp[v[i].second] == 0)
            num++;
        else
            x.push_back(v[i].first);
        sum = sum + v[i].first;
        mp[v[i].second]++;
    }
    reverse(x.begin(), x.end());
    sum = sum + num * num;

    for (i = k; i < n; i++)
    {
        if (mp[v[i].second] == 0)
            y.push_back(v[i].first);
        mp[v[i].second]++;
    }
    ll ans = sum;
    for (i = 0; i < min(x.size(), y.size()); i++)
    {
        sum = sum - (x[i] - y[i]);
        num++;
        sum = sum + (num * num) - (num-1)*(num-1);
        ans = max(ans, sum);
    }
    cout << ans << "\n";

    return (0);
}