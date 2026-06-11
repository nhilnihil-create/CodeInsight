#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define rep(i,init,n) for(int i=init;i<n;i++)
#define rev(i,n,init) for(int i=n;i>=init;i--)
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<=b ? a : b)


#define pb push_back
#define f first
#define s second
const int N = 1e5+5;
using namespace std;
int tb[3][N];
int dp[N][3];
long long solve(int i,int p,int n)
{
    if(i>=n)return 0;
    if(dp[i][p]!=-1)return dp[i][p];
    int t = max(tb[(p+1)%3][i]+solve(i+1,(p+1)%3,n),tb[(p+2)%3][i]+solve(i+1,(p+2)%3,n));
    return dp[i][p]=t;
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    int n;
    cin >> n;
    rep(i,0,n)cin >> tb[0][i] >> tb[1][i] >> tb[2][i];
    memset(dp,-1,sizeof(dp));
    cout << max(solve(0,0,n),max(solve(0,1,n),solve(0,2,n)));
    return 0;
}
