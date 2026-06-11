#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,p,sr,sc;
char s[N],t[N];
bool walk1()
{
    int L=1,R=n;
    for(int i=p;i;i--)
    {
        if(t[i]=='U')R=min(n,R+1);else if(t[i]=='D')L=max(1,L-1);
        if(s[i]=='U')L++;else if(s[i]=='D')R--;
        if(L>R)return 1;
    }
    return (sr<L||sr>R);
}
bool walk2()
{
    int L=1,R=m;
    for(int i=p;i;i--)
    {
        if(t[i]=='L')R=min(m,R+1);else if(t[i]=='R')L=max(1,L-1);
        if(s[i]=='L')L++;else if(s[i]=='R')R--;
        if(L>R)return 1;
    }
    return (sc<L||sc>R);
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&p,&sr,&sc);
    scanf("%s",s+1);
    scanf("%s",t+1);
    if(walk1()||walk2())puts("NO");
    else puts("YES");
}