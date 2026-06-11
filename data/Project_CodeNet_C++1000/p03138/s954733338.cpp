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


int main()
{
    ll N, K; cin >> N >> K;
    vll A(N); rep(i, N) cin >> A[i];

    vll cnt(60);
    rep(i, 60) {
        // i桁目に注目
        rep(j, A.size()) {
            cnt[i] += ((A[j] >> i) & 1ll);
        }
    }

    //for (auto elem : cnt) cout << elem << " "; cout << endl;

    ll sum = 0;
    ll x = 0;
    for (ll i = 59; i >= 0; i--) {
        if (x + (1ll << i) <= K && (N - cnt[i]) >= cnt[i]) {
            x += (1ll << i);
            sum += (N - cnt[i]) * (1ll << i);
        } else {
            sum += cnt[i] * (1ll << i);
        }
        //cout << "x: " << x << endl;
    }
    cout << sum << endl;
    return 0;
}