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
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    ll ans = 0;
    rep(i, n) {
        bool f = true;
        rep(ii, n) {
            rep(iii, n) {
                if (s[ii][(iii + (n - i)) % n] != s[iii][(ii + (n - i)) % n]) {
                    f = false;
                    break;
                }
            }
            if (!f) break;
        }
        if (f) ans += n;
    }
    cout << ans << endl;
    return 0;
}
