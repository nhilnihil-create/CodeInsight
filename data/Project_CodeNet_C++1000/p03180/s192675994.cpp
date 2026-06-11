#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 10000000000000000
#define int long long
int N;
int dp[1<<16];
int a[16][16];

int f(int S) {
    
    if (dp[S] != -INF2) return dp[S];
    int sum = 0;
    rep(i, N) {
        REP(j, i + 1, N - 1) {
            if ((S & (1 << i)) && (S & (1 << j)) ) sum += a[i][j];
        }
    }
    for(int T = (S - 1) & S; T > 0; T=(T - 1) & S) {
        dp[S] = max(dp[S], f(T) + f(S^T));
    }
    dp[S] = max(sum, dp[S]);
    //cout << bitset<4>(S) << " " << dp[S] << endl;
    return dp[S];
}


signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) {
        rep(j, N) {
            cin >> a[i][j];
        }
    }
    rep(i, (1<<N)) dp[i] = -INF2;
    cout << f((1<<N) - 1) << endl;

    return 0;
}
