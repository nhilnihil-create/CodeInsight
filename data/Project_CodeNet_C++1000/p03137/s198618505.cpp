#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i, 0, m) cin >> a[i];
    ll ans = 0;
    if (n >= m)
        ans = 0;
    else
    {
        sort(all(a));
        ll tmp = a[a.size() - 1] - a[0];
        priority_queue<ll> mp;
        rep(i, 0, m - 1) mp.push(a[i + 1] - a[i]);
        rep(i, 0, n - 1)
        {
            ll t = mp.top();
            mp.pop();
            tmp -= t;
        }
        ans = tmp;
    }
    cout << ans << endl;
}