#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define llong long long
using namespace std;
 
inline int read()
{
    int x=0; bool f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
    for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
    if(f) return x;
    return -x;
}
 
const int N = 5000;
const llong INF = 10000000000000000ll;
int p[N+3],pp[N+3];
llong dp[N+3][N+5],sdp[N+3][N+5];
int n; llong arga,argb;
 
void update(llong &x,llong y) {x = x<y?x:y;}
 
int main()
{
    scanf("%d%lld%lld",&n,&arga,&argb);
    for(int i=1; i<=n; i++) {scanf("%d",&p[i]); pp[p[i]] = i;}
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = INF;
    for(int i=0; i<=n; i++) dp[0][i] = 0ll;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(j==pp[i]) {update(dp[i][j],dp[i-1][j-1]);}
            llong tmp = dp[i-1][j]+(j<pp[i]?argb:arga);
            update(dp[i][j],tmp);
        }
        for(int j=1; j<=n; j++) dp[i][j] = min(dp[i][j-1],dp[i][j]);
    }
    llong ans = dp[n][n];
    printf("%lld\n",ans);
    return 0;
}