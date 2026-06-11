#include<bits/stdc++.h>
using namespace std;
const int N=310;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
char s[N];
int n,k,f[N][N][N];
int main() {
    scanf("%s",s+1),n=strlen(s+1);
    k=gi();
    for(int l=n;l;l--)
        for(int r=l;r<=n;r++)
            for(int i=0;i<=k;i++) {
                if(l==r) f[l][r][i]=1;
                else if(l+1==r) f[l][r][i]=(i||s[l]==s[r])?2:1;
                else {
                    f[l][r][i]=max(f[l+1][r][i],f[l][r-1][i]);
                    if(s[l]==s[r]) f[l][r][i]=max(f[l][r][i],f[l+1][r-1][i]+2);
                    if(i) f[l][r][i]=max(f[l][r][i],f[l+1][r-1][i-1]+2);
                }
            }
    printf("%d\n",f[1][n][k]);
    return 0;
}
