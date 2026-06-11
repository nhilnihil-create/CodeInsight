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
const int N=1e5+5;
using namespace std;
int h[N];
int dp[N];
int solve(int i,int n)
{
    if(i>=n-1)return 0;
    if(dp[i]!=-1)return dp[i];
    int t = abs(h[i]-h[i+1]);
    if(i+2<n)t=min(abs(h[i]-h[i+2])+solve(i+2,n),t+solve(i+1,n));
    return dp[i]=t;

}
int main()
{
    ios::sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    rep(i,0,n)cin >> h[i];
    cout << solve(0,n);

    return 0;
}
