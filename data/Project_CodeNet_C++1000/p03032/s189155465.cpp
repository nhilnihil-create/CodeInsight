#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll ans = LONG_LONG_MIN;
    rep(left, k + 1) {
        rep(right, k + 1 - left) {
            if ((left + right) > n) continue;
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            ll tmp = 0;
            rep(i, left) {
                pq.push(v[i]);
                tmp += v[i];
            }
            rep(i, right) {
                pq.push(v[n - 1 - i]);
                tmp += v[n - 1 - i];
            }
            rep(i, k - (left + right)) {
                if (pq.empty()) break;
                ll v = pq.top(); pq.pop();
                if (v >= 0) break;
                tmp -= v;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
