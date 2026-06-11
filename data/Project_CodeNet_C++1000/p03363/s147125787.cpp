#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> cum(n + 1, 0);
    rep(i, n) cum[i + 1] = cum[i] + a[i];

    map<ll, ll> mp;
    rep(i, n + 1)
    {
        mp[cum[i]]++;
    }

    ll ans = 0;
    for (auto itr: mp)
    {
        ll nn = itr.second;
        ans += nn * (nn - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}