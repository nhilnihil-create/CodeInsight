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
    string s;
    cin >> s;
    string ls = s.substr(0, n);
    string rs = s.substr(n, n);
    reverse(all(rs));
    map<pair<string, string>, ll> lcnt;
    rep(i, 1 << n) {
        string ls1 = "", ls2 = "";
        rep(ii, n) {
            if ((i & (1 << ii)) != 0) {
                ls1 += ls[ii];
            }
            else {
                ls2 += ls[ii];
            }
        }
        lcnt[make_pair(ls1, ls2)]++;
    }
    ll ans = 0;
    rep(i, 1 << n) {
        string rs1 = "", rs2 = "";
        rep(ii, n) {
            if ((i & (1 << ii)) != 0) {
                rs1 += rs[ii];
            }
            else {
                rs2 += rs[ii];
            }
        }
        ans += lcnt[make_pair(rs1, rs2)];
    }
    cout << ans << endl;
    return 0;
}
