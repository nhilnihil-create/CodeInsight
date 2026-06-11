#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> a(n), from(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> m;
    ll ans = 0;//, mv = LONG_LONG_MIN;
    rep(i, n) {
        from[i] = i - a[i];
        // if ((from[i] < 0) || (i < from[i]) || (mv > a[i])) {
        if ((from[i] < 0) || (i < from[i])) {
            cout << -1 << endl;
            return 0;
        }
        // mv = max(mv, a[i]);
        if ((i != 0) && (a[i] > (a[i - 1] + 1))) {
            cout << -1 << endl;
            return 0;
        }
        // printf("i=%lld, m[%lld]=%lld, ans=%lld, %lld\n", i, from[i], m[from[i]], ans, i - m[from[i]]);
        ans += i - max(from[i], m[from[i]]);
        m[from[i]] = i;
    }
    cout << ans << endl;
    // rep(i, n) printf("%lld%s", from[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
