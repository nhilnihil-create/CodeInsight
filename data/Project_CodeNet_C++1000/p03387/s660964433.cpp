#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    vector<ll> v(3);
    rep(i, 3) cin >> v.at(i);

    ll odd = 0, even = 0;
    rep(i, 3) {
        if (v.at(i) % 2 == 0) even++;
        else odd++;
    }

    ll ans = 0;
    if (odd == 2) {
        ans++;
        rep(i, 3) {
            if (v.at(i) % 2 != 0) v.at(i)++;
        }
    } else if (even == 2) {
        ans++;
        rep(i, 3) {
            if (v.at(i) % 2 == 0) v.at(i)++;
        }
    }

    ll ma = max(v.at(0), max(v.at(1), v.at(2)));
    rep(i, 3) ans += (ma - v.at(i)) / 2;
    cout << ans << endl;
}