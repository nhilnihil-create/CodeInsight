#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<P> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    ll ans = 0;
    ll cnt = 0;
    ll i = 0;
    do {
        cnt += a[i].second;
        ans += a[i].first * a[i].second;
        i++;
    } while(cnt < m);
    ans -= (cnt - m) * a[i - 1].first;
    cout << ans << endl;
    return 0;
}
