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
    ll N, T, A; cin >> N >> T >> A;
    vector<ld> H(N);
    rep(i, N) cin >> H.at(i);

    map<ld, ld> ch;
    rep(i, N) ch[i] = abs(A - (T - (H.at(i) * 0.006)));

    ld res = 1e9, ans = 0;
    rep(i, N) {
        res = min(res, ch[i]);
        if (res == ch[i]) ans = i + 1;
    }
    cout << ans << endl;
}