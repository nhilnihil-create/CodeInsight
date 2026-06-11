#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 5;
int n,m;
char s[maxn];
int dp[maxn][maxn][maxn];
int main () {
    int ans = 0;
    scanf(" %s%d",s,&m);
    n = strlen(s);
    for(int i=n;i>=1;i--) s[i] = s[i-1];
    for(int l=1;l<=n;l++) {
        for(int r=n;r>=l;r--) {
            for(int k=0;k<=m;k++) {
                int t = max(dp[l-1][r][k], dp[l][r+1][k]);
                if(s[l]==s[r]) t = max(t, dp[l-1][r+1][k] + 1);
                if(k>0) t = max(t, dp[l-1][r+1][k-1] + 1);
                dp[l][r][k] = t;
                ans = max(ans, dp[l][r][k]*2 - (l==r ? 1 : 0));
//                printf("dp %d %d %d = %d (%c and %c)\n",l,r,k,dp[l][r][k],s[l],s[r]);
            }
        }
    }
    printf("%d",ans);
}
