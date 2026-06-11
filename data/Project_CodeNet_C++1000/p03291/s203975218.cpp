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
string S; 
int dp[100010][4];

int calc(int x, int p) {
    if(dp[x][p] != -1) return dp[x][p];
    if(x >= S.length()) {
        if(p == 3) return dp[x][p] = 1;
        else return dp[x][p] = 0;
    }
    if(S[x] != '?') {
        if(S[x] == 'A' && p == 0) return dp[x][p] = (calc(x + 1, 1) + calc(x + 1, 0)) % mod;
        if(S[x] == 'B' && p == 1) return dp[x][p] = (calc(x + 1, 2) + calc(x + 1, 1)) % mod;
        if(S[x] == 'C' && p == 2) return dp[x][p] = (calc(x + 1, 3) + calc(x + 1, 2)) % mod;
        return dp[x][p] = calc(x + 1, p);
    }
    if (p != 3) return dp[x][p] = (calc(x + 1, p + 1) + calc(x + 1, p) * 3) % mod;
    return dp[x][p] = (calc(x + 1, p) * 3) % mod;

}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    rep(i, 100010) rep(j, 4) dp[i][j] = -1;
    cout << calc(0, 0) << endl;

    return 0;
}
