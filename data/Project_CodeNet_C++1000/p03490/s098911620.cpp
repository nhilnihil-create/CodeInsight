#include<bits/stdc++.h>

using namespace std;

#define N 12000

int n,x,y,d,cnt[2],c[2][N];
bool f[N],g[N];
char s[N];

int main(){
    scanf("%s%d%d",s+1,&x,&y); n=strlen(s+1);
    int i;
    for (i=1;i<=n && s[i]=='F';i++) x--;
    d=0;
    for (;i<=n;i++)
        if (s[i]=='F'){c[d][c[d][0]]++; cnt[d]++;}
        else{d^=1; c[d][0]++;}
    x=abs(x); y=abs(y);
    if ((cnt[0]+x)&1 || (cnt[1]+y)&1){puts("No"); return 0;}
    x=(cnt[0]+x)>>1; y=(cnt[1]+y)>>1;
    f[0]=1;
    for (int i=1;i<=c[0][0];i++)
        for (int j=x;j>=c[0][i];j--)
            f[j]|=f[j-c[0][i]];
    g[0]=1;
    for (int i=1;i<=c[1][0];i++)
        for (int j=y;j>=c[1][i];j--)
            g[j]|=g[j-c[1][i]];
    if (f[x] && g[y]) puts("Yes");
    else puts("No");

    return 0;
}
