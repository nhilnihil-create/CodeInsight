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

int N, K;
vector<int> a;
int memo[2][101010];

// 0なら先手の負け、1なら勝ち
// 1が先手、0が後手
int dfs(int now, int turn) {
    if(now == 0) {
        return (!turn);
    }
    if(memo[turn][now] != -1) {
        return memo[turn][now];
    }
    bool win = false;
    for(int i = 0; i < N; i++) {
        if(now - a[i] >= 0) {
            win |= (dfs(now - a[i], 1 - turn) == turn);
        }
    }
    if(turn) {
        return memo[turn][now] = win;
    } else {
        return memo[turn][now] = (!win);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 101010; j++) {
            memo[i][j] = -1;
        }
    }
    bool win = dfs(K, 1);
    cout << (win ? "First" : "Second") << "\n";
}