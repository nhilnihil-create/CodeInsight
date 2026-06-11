#include <algorithm>
#include <iostream>
using namespace std;

struct block {
    int w, s, v;
};
// 比較関数
bool comp(block a, block b) { return a.w + a.s < b.w + b.s; }

int N;
block B[1009];
long long dp[1009][20009];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int w, s, v;
        cin >> w >> s >> v;
        B[i] = block{w, s, v};
    }

    sort(B, B + N, comp);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 20000; j++) {
            dp[i + 1][j] = dp[i][j];
            if(j >= 1) dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
            if(j >= B[i].w && j - B[i].w <= B[i].s)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - B[i].w] + B[i].v);
        }
    }

    cout << dp[N][20000] << endl;

    return 0;
}