#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a+2), t(b+2);
    s[0] = -LINF, s[a+1] = LINF;
    t[0] = -LINF, t[b+1] = LINF;
    REP(i, 1, a+1) cin >> s[i];
    REP(i, 1, b+1) cin >> t[i];

    rep(i, q) {
        ll x;
        cin >> x;
        int si = lower_bound(s.begin(), s.end(), x) - s.begin();
        int ti = lower_bound(t.begin(), t.end(), x) - t.begin();

        ll res = LINF;
        rep(i, 2) {
            rep(j, 2) {
                ll sx = s[si-i];
                ll tx = t[ti-j];
                ll d1 = abs(sx - x) + abs(tx - sx);
                ll d2 = abs(tx - x) + abs(sx - tx);
                res = min({res, d1, d2});
            }
        }
        cout << res << endl;
    }

    return 0;
}