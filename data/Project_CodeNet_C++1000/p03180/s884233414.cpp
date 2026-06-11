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

#define DEBUG
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<ll>> a(N, vector<ll>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    vector dp(1 << N, -LLINF);
    for(int S = 0; S < (1 << N); S++) {
        dp[S] = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if((S & (1 << i)) && (S & (1 << j))) {
                    dp[S] += a[i][j];
                }
            }
        }
        for(int T = (S - 1) & S; T > 0; T = ((T - 1) & S)) {
            chmax(dp[S], dp[T] + dp[S ^ T]);
        }
    }
    cout << dp[(1 << N) - 1] << endl;
}