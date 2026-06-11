#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 200010
#define MAX_DP 70000000

string S;
int h[MAX_N];       // [0, i) で各アルファベットの偶奇を表す。奇数なら 1
int opt[MAX_N];     // [0, i) の最小分割数
int dp[MAX_DP];

// [r, l) の範囲で回文作成可能かチェック
// 可能なら true
//bool Check(int r, int l) {
//    int odd = 0;
//    REP(i, 32) { if((((h[r] ^ h[l]) >> i) & 1) == 1) { odd++; } }
//    return (odd <= 1) ? true : false;
//}

int main()
{
    cin >> S;

    // ハッシュ作成
    ZERO(h);
    for(int i = 0; i < S.length(); ++i) { h[i+1] = ( h[i] ^ (1 << (S[i] - 'a')) ); }

    REP(i, MAX_DP) { dp[i] = INF; }
    REP(i, MAX_N) { opt[i] = INF; }
    opt[0] = 0;
    dp[0] = 0;
    for(int i = 1; i <= S.length(); ++i) {
        for(int j = 0; j <= 26; ++j) {
            int x = (j < 26) ? (1 << j) : 0;
            opt[i] = min(opt[i], dp[(h[i] ^ x)] + 1);
        }
        //if(opt[i] >= INF)
        //{
        //    for(int j = 0; j < i; ++j) {
        //        if(Check(j, i)) { opt[i] = min(opt[i], opt[j] + 1); }
        //    }
        //}
        dp[h[i]] = min(dp[h[i]], opt[i]);
    }
    printf("%d\n", opt[S.length()]);

    return 0;
}
