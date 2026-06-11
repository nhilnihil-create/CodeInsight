#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    int N;
    cin >> N;
    struct block {
        int w;
        int s;
        int v;
        bool operator<(const block& b) const {
            return s - b.w > b.s - w;
        }
    };
    vector<block> blocks(N);
    int max_solidity = 0;
    for (int i = 0; i < N; i++) {
        cin >> blocks[i].w >> blocks[i].s >> blocks[i].v;
        max_solidity = max(max_solidity, blocks[i].s);
    }
    max_solidity *= 2;
    sort(begin(blocks), end(blocks));
    const int INF = 1e9;
    vector<long> dp(max_solidity + 1, -INF);
    dp[max_solidity] = 0;
    long res = 0;
    for (int i = 0; i < N; i++) {
        block b = blocks[i];
        for (int solidity = b.w; solidity <= max_solidity; solidity++) {
            int s = min(b.s, solidity - b.w);
            dp[s] = max(dp[s], dp[solidity] + b.v);
            res = max(res, dp[s]);
        }
    }
    cout << res << endl;
    return 0;
}
