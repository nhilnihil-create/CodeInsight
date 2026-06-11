#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

#ifdef DEBUG
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
#else
template <class T, class... Args>
void debug(const T &x, const Args &... args) {}
template <class T> void debugVector(const vector<T> &v) {}
#endif

using ll = long long;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

struct Data {
    int w, s, v;
    Data() {}
    Data(int w, int s, int v) : w(w), s(s), v(v) {}
};

ll dp[1010][20010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<Data> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i].w >> a[i].s >> a[i].v;
    }
    sort(ALL(a),
         [](const Data &x, const Data &y) { return (x.s + x.w < y.s + y.w); });
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 20010; j++) {
            if(j <= a[i].s) {
                chmax(dp[i + 1][j + a[i].w], dp[i][j] + a[i].v);
            }
            chmax(dp[i + 1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    for(int j = 0; j < 20010; j++) {
        chmax(ans, dp[N][j]);
    }
    cout << ans << endl;
}