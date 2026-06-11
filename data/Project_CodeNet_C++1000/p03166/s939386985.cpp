#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(r) (r).begin(), (r).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

const int64_t MAX_N = 100010;
int64_t N, M, x, y, R = 0;
vector<int64_t> G[MAX_N];
int64_t dp[MAX_N];

int64_t solve(int x) {
    if (dp[x] != -1) return dp[x];
    int64_t r = 0;
    for (const auto& i : G[x]) {
        chmax(r, solve(i)+1);
    }
    return dp[x] = r;
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }
    rep(i, N) dp[i] = -1;

    rep(i, N) chmax(R, solve(i));
    cout << R << endl;
}
