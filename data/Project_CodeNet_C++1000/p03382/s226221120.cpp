#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n;
map<ll, ll> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    rep(i, n)
    {
        cin >> a[i];
        chmax(mx, a[i]);
        mp[a[i]]++;
    }
    ll k = (mx + 1) / 2;
    ll d = k;
    ll mi=k;
    for (auto &it : mp)
    {
        if (it.first != mx)
        {
            if (abs(it.first - k) <= d)
            {
                d=abs(it.first - k);
                mi=it.first;
            }
        }
    }
    if (mp[k] == 0 || k == mx)
        k = mx - k;
    cout << mx << " " << mi << endl;
    return 0;
}
