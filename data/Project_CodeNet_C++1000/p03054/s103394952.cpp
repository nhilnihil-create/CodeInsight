#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n,m,k;
int posx,posy,lx,rx;
char s1[Maxn],s2[Maxn];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&posx,&posy);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    bool ans=true;
    lx=1,rx=n;
    for (int i=k;i;i--)
    {
        if (s2[i]=='D')
        {
            if (lx>1) --lx;
        } else if (s2[i]=='U')
        {
            if (rx<n) ++rx;
        }
        if (s1[i]=='D')
        {
            --rx;
            if (rx<lx) ans=false;
        } else if (s1[i]=='U')
        {
            ++lx;
            if (rx<lx) ans=false;
        }
    }
    if (!(lx<=posx&&posx<=rx)) ans=false;
    lx=1,rx=m;
    for (int i=k;i;i--)
    {
        if (s2[i]=='R')
        {
            if (lx>1) --lx;
        } else if (s2[i]=='L')
        {
            if (rx<m) ++rx;
        }
        if (s1[i]=='R')
        {
            --rx;
            if (rx<lx) ans=false;
        } else if (s1[i]=='L')
        {
            ++lx;
            if (rx<lx) ans=false;
        }
    }
    if (!(lx<=posy&&posy<=rx)) ans=false;
    if (ans) printf("YES\n"); else printf("NO\n");
    return 0;
}