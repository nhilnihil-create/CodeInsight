#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ull = unsigned long long;
using bit = bitset<40>;
#define chmax(x,y) x=max(x,y)

ull dp[41][2]; // dp[i][smaller] : 上からi桁目までみたときのxorの最大値

int main() 
{
    ull n, k;
    cin >> n >> k;

    vector<ull> A(n);
    rep(i,n) cin >> A[i];

    int S[41]; // 上からi桁目が1の個数
    S[0] = 0;
    for(int i=1; i<=40; i++) {
        S[i] = 0;
        for(auto a : A) {
            bit ba = a;
            if(ba[40-i] == 1) S[i]++;
        }
    }

    rep(i,41)rep(j,2) dp[i][j] = 0;
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i=1; i<=40; i++) {
        ull n1 = S[i]; // 1の個数
        ull n0 = n-n1; // 0の個数

        int j = 40-i;

        ull x = (k>>j)&1;
        if (x == 0) {
            // 0を選ぶ
            chmax(dp[i][0], dp[i-1][0] + n1 * (1ULL<<j));
            if (dp[i-1][1]>0) chmax(dp[i][1], dp[i-1][1] + n1 * (1ULL<<j));
            // 1を選ぶ
            if (dp[i-1][1]>0) chmax(dp[i][1], dp[i-1][1] + n0 * (1ULL<<j));
        } else {
            // 0を選ぶ
            chmax(dp[i][1], max(dp[i-1][0] + n1 * (1ULL<<j), dp[i-1][1] + n1 * (1ULL<<j)));
            // 1を選ぶ
            chmax(dp[i][0], dp[i-1][0] + n0 * (1ULL<<j));
            if (dp[i-1][1]>0) chmax(dp[i][1], dp[i-1][1] + n0 * (1ULL<<j));
        }
    }

    cout << max(dp[40][0], dp[40][1]) << endl;

    return 0;
}
