#include <bits/stdc++.h>
using namespace std;
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
    int N, M; cin >> N >> M;
    vector<ll> X(M);
    rep(i, M) cin >> X[i];
    sort(ALL(X));

    vector<ll> diffs;
    foreps(i, 1, M) diffs.push_back(X[i] - X[i - 1]);
    sort(ALL(diffs), greater<ll>());

    ll ans = X.back() - X[0];
    for (int i = 0; i < min(len(diffs), N - 1); i++) ans -= diffs[i];
    cout << ans << endl;
}