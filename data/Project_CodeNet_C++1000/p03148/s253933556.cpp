#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> v(n);
    rep(i, n)
    {
        int t, d;
        cin >> t >> d;
        v[t - 1].push_back(d);
    }
    rep(i, n)
    {
        sort(v[i].begin(), v[i].end(), greater<ll>());
    }
    priority_queue<ll> top;
    priority_queue<ll> other;
    priority_queue<ll, vector<ll>, greater<ll>> res;
    ll s = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (j == 0)
            {
                top.push(v[i][j]);
            }
            else
            {
                other.push(v[i][j]);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (other.empty())
        {
            break;
        }
        ll t = other.top();
        s += t;
        other.pop();
        res.push(t);
    }
    for (ll i = 1; i <= k; i++)
    {
        if (top.empty())
        {
            break;
        }
        ll t = top.top();
        top.pop();
        s += t;
        if (res.size() + i > k)
        {
            ll r = res.top();
            s -= r;
            res.pop();
        }
        ans = max(ans, s + i * i);
    }
    cout << ans << endl;
}