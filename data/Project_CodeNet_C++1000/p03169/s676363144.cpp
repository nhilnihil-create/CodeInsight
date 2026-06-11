#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

double dp[301][301][301];

void solve() {
    int N; cin >> N;
    map<int, int> cnt;
    rep(i, N) {
        int s; cin >> s;
        cnt[s]++;
    }
    auto f = [&](auto &&f, int a, int b, int c) -> double {
        if(a + b + c == 0) return 0;
        if(dp[a][b][c]) return dp[a][b][c];
        double p = 1.0 - double(N - a - b - c) / N;
        double ret = 1.0 / p;
        if(a) ret += f(f, a - 1, b, c) * a / N / p;
        if(b) ret += f(f, a + 1, b - 1, c) * b / N / p;
        if(c) ret += f(f, a, b + 1, c - 1) * c / N / p;
        return dp[a][b][c] = ret;
    };
    cout << fixed << setprecision(15) << f(f, cnt[1], cnt[2], cnt[3]) << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
