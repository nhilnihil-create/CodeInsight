#include<bits/stdc++.h>
using namespace std;
#define R freopen("A.in","r",stdin);
#define W freopen("A.out","w",stdout);
const int N=305;
char s[N];
int k,d[N][N][N],n;
int dp(int i,int j,int x)
{
    if(i==j)return 1;
    if(i>j)return 0;
    int& ans=d[i][j][x];
    if(ans!=-1)return ans;
    if(s[i]==s[j])ans=dp(i+1,j-1,x)+2;
    else if(x)ans=max(max(dp(i,j-1,x),dp(i+1,j,x)),dp(i+1,j-1,x-1)+2);
         else ans=max(dp(i,j-1,x),dp(i+1,j,x));
    return ans;
}
int main()
{
    
    memset(d,-1,sizeof d);
    scanf("%s%d",s,&k);
    n=strlen(s);
    cout<<dp(0,n-1,k);
    return 0;
}
