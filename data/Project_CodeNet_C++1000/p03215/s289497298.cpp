#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(n + 1, 0);
    rep(i, n) dp[i + 1] = dp[i] + a[i];
    multiset<ll> b;
    reps(l, 1, n + 1) {
        reps(r, l, n + 1) {
            b.insert(dp[r] - dp[l - 1]);
        }
    }
    ll ans = 0;
    rrep(i, 40) {
        ll bit = 1LL << i;
        ll cnt = 0;
        auto it = b.end(); it--;
        set<ll> s;
        while(true) {
            if ((*it & bit) == bit) cnt++;
            else s.insert(*it);
            if (it == b.begin()) break;
            it--;
        }
        if (cnt >= k) {
            ans |= bit;
            for(auto x : s) b.erase(x);
        }
        // printf("i=%lld, cnt=%lld, ans=%lld\n", i, cnt, ans);
    }
    cout << ans << endl;
    return 0;
}
