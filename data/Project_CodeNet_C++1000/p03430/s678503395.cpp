#include<bits/stdc++.h>
using namespace std;
const int N=303;
int n,f[N][N][N],p,ans;char s[N];
int main(){
    scanf("%s%d",s+1,&p);n=strlen(s+1);
    for(int i=n;i;i--)
        for(int j=i;j<=n;j++)
            for(int k=0;k<=(j-i)/2+1;k++)
                f[i][j][k]=max(k||s[i]==s[j]?f[i+1][j-1][k-!!(s[i]^s[j])]+1+!!(i^j):0,max(f[i][j-1][k],f[i+1][j][k]));
    for(int i=0;i<=p;i++)ans=max(ans,f[1][n][i]);
    cout<<ans;
    return 0;
}