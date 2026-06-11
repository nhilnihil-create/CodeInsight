#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <stack>
#include <vector>
#include <random>
#include <string.h>
#include <stdio.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef pair<int, int> ii;
typedef pair<long double, int> id;
typedef pair<long long, long long> llp;
const int N = 1e3+1, MOD = 1e9+7;
int n, m;
int dp[N][N], a[N][N];
bool check(int x, int y) {
    return (x>0&&x<=n&&y>0&&y<=m&&a[x][y]);
}
int main() {
    //freopen("ee.inp", "r", stdin);
    //freopen("ee.OUT", "w", stdout);
    fastIO;
    cin>>n>>m;
    string s;
    for(int i=1;i<=n&&cin>>s;i++)
        for(int j=1;j<=m;j++)
            a[i][j] = (s[j-1]=='#'?0:1);
    dp[n][m] = 1;
    for(int i=n;i>0;i--)
        for(int j=m;j>0;j--) {
            if (!a[i][j]) continue;
            if (check(i+1, j)) dp[i][j]+=dp[i+1][j]%MOD;
            if (check(i, j+1)) dp[i][j]+=dp[i][j+1]%MOD;
            dp[i][j]%=MOD;
        }
    cout << dp[1][1];
}
