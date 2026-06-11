#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), cum(n + 1, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) cum[i + 1] = cum[i] + a[i];

    ll res = 0;
    map<ll, ll> mp;
    rep(i, n + 1) mp[cum[i]]++;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        ll n = itr->second;
        res += n * (n - 1) / 2;
    }

    cout << res << '\n';
    return 0;
}
