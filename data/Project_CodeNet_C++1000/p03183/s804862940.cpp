#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

const int MAXN = 1005;
const int MAX_S = (int)1e4 + 5;
const long long INF_LL = (long long)1e16;

struct Block {
    int w, s, v;

    Block() {}
    Block(int w, int s, int v):w(w), s(s), v(v) {}
};


long long dp[MAXN][2 * MAX_S];
vector<Block> blocks;

bool operator<(const Block& a, const Block& b) {
    return a.w + a.s > b.w + b.s;
}

int main(void) {
    int n;
    int w, s, v;

    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d %d %d", &w, &s, &v);
        blocks.pb(Block(w, s, v));
    }

    sort(blocks.begin(), blocks.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_S; j++) {
            if (i > 0) dp[i][j] = dp[i - 1][j];
            if (j <= blocks[i].s) dp[i][j] = max(dp[i][j], 1LL * blocks[i].v);

            if (i > 0 && j - blocks[i].w >= 0) {
                dp[i][min(j - blocks[i].w, blocks[i].s)] = max(dp[i][min(j - blocks[i].w, blocks[i].s)], blocks[i].v + dp[i - 1][j]);
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j < MAX_S; j++) {
        ans = max(ans, dp[n - 1][j]);
    }
    printf("%lld\n", ans);

    return 0;
}
