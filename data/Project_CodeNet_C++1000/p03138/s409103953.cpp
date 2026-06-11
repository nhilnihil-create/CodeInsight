#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, K; cin >> N >> K;
    vll A(N); rep(i, N) cin >> A[i];

    vll DS(60, 0);
    rep(k, 60) {
        rep(i, N) {
            DS[k] += ((A[i] >> k) & 1);
        }
    }
    // for (auto elem : DS) cout << elem << " "; cout << endl;
    
    ll k = 0, ans = 0;
    for (ll bit = 59; bit >= 0; bit--) {
        if (DS[bit] * 2 < N && k + (1ll<<bit) <= K) {
            k += (1ll<<bit);
            ans += (N - DS[bit]) * (1ll<<bit);
        } else {
            ans += DS[bit] * (1ll<<bit);
        }
    }
    cout << ans << endl;
    return 0;
}