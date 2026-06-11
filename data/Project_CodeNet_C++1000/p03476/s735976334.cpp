#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll Q; cin >> Q;
    vll l(Q), r(Q); rep(i, Q) cin >> l[i] >> r[i];

    ll N = 1e5+10;
    vector<bool> is_prime(N, true);
    is_prime[1] = false;
    for (ll i = 2; i < N; i++) {
        if (is_prime[i]) for (ll j = 2 * i; j < N; j += i) is_prime[j] = false;
    }

    vector<bool> is_like(N, false);
    for (ll i = 1; i < N; i += 2) {
        is_like[i] = (is_prime[i] && is_prime[(i + 1) / 2]);
    }

    vll sum(N);
    rep(i, N) if (i == 0) sum[i] = is_like[i]; else sum[i] = sum[i-1] + is_like[i];

    //rep(i, 60) cout << i << ": " << sum[i] << endl;

    rep(i, Q) {
        cout << sum[r[i]] - sum[l[i]-1] << endl;
    }
    return 0;
}