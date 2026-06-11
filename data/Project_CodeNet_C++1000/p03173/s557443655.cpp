#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
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
int dp[410][410];
int a[410];
int N; 
int sum[410];
int calc(int L = 0, int R = N - 1) {
    if(L > R) return 0;
    if(L == R) return a[L];
    if(dp[L][R] != -1) return dp[L][R];
    int ret = INF2;
    REP(i, L, R - 1) {
        int tmp = calc(L, i) + calc(i + 1, R) + sum[R + 1] - sum[L];
        ret = min(ret, tmp);
    }

    return dp[L][R] = ret;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, 410) rep(j, 410) dp[i][j] = -1;
    rep(i, N) sum[i + 1] = sum[i] + a[i];
    cout << calc()- sum[N] << endl;

    return 0;
}
