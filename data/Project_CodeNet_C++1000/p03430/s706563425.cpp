#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAX=310;
const int INF=998877;
char s[MAX];
int n,k,dp[MAX][MAX][MAX];
int build(int l,int r,int c){
    if(c>k) return -INF;
    if(l>=r) return 0;
    if(dp[l][r][c]==0){
        int t=(s[l]==s[r-1]);
        if(l==r-1) dp[l][r][c]=build(l+1,r-1,c+1-t)+1;
        else dp[l][r][c]=build(l+1,r-1,c+1-t)+2;
        dp[l][r][c]=max(dp[l][r][c],build(l+1,r,c));
        dp[l][r][c]=max(dp[l][r][c],build(l,r-1,c));
    }
    return dp[l][r][c];
}
int main(){
    scanf("%s%d",s,&k);
    n=strlen(s);
    printf("%d\n",build(0,n,0));
}
