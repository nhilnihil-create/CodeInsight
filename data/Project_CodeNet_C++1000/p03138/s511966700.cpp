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
#define INF2 1000000000000000000
#define int long long

int dp[64][2];
int n, k;
int A[100010];
int calc(int x, int smaller) {
    //cout << x << " " << smaller << endl;
    if(x == -1) return 0;
    if(dp[x][smaller] != -1) return dp[x][smaller];
    int cnt1 = 0, cnt0 = 0;
    rep(i, n) {
        if((1LL << x) & A[i]) cnt1++;
        else cnt0++;
    }
    int num0 = cnt0 * (1LL << x);
    int num1 = cnt1 * (1LL << x);
    if(smaller)
        return dp[x][smaller] = max(num0, num1) + calc(x - 1, 1);
    if((1LL << x) & k) {
        return dp[x][smaller] = max(num1 + calc(x - 1, 1), num0 + calc(x - 1, 0));
    } else {
        return dp[x][smaller] = num1 + calc(x - 1, 0);
    }
    
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    rep(i, n) cin >> A[i];
    rep(i, 64) rep(j, 2) dp[i][j] = -1;
    cout << calc(60, 0) << endl;
    // rep(i, 60) {
    //     cout << i << ":";
    //     rep(j, 2) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    

    return 0;
}
