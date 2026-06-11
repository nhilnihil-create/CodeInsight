#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> black_cnt(N + 1);
    vector<int> white_cnt(N + 1);
    rep(i, N) {
        int black = (S[i] == '#') ? 1 : 0;
        black_cnt[i + 1] = black_cnt[i] + black;

        int white = (S[i] == '.') ? 1 : 0;
        white_cnt[i + 1] = white_cnt[i] + white;
    }

    int ans = N;
    rep(i, N + 1) { // i番目以降をblackにする
        int cnt = black_cnt[i] + white_cnt[N] - white_cnt[i];
        chmin(ans, cnt);
    }
    cout << ans << endl;
}