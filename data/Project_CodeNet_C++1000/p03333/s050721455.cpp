#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=998244353,inf=0x3f3f3f3f;
int n,m,k,t,pl[maxn],pr[maxn],id1[maxn],id2[maxn];
bool vis[maxn];
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&pl[i],&pr[i]),id1[i]=id2[i]=i;
    sort(id1+1,id1+n+1,[](int x,int y){return pl[x]>pl[y];});
    sort(id2+1,id2+n+1,[](int x,int y){return pr[x]<pr[y];});
    long long ret1=0,ret2=0;
    int pos=0;
    for(i=1;i<=n;i++)
    {
        if(pl[id1[i]]>pos)
            ret1+=pl[id1[i]]-pos,pos=pl[id1[i]];
        if(pr[id2[i]]<pos)
            ret1+=pos-pr[id2[i]],pos=pr[id2[i]];
    }
    ret1+=abs(pos);
    pos=0;
    for(i=1;i<=n;i++)
    {
        if(pr[id2[i]]<pos)
            ret2+=pos-pr[id2[i]],pos=pr[id2[i]];
        if(pl[id1[i]]>pos)
            ret2+=pl[id1[i]]-pos,pos=pl[id1[i]];
    }
    ret2+=abs(pos);
    printf("%lld\n",max(ret1,ret2));
    return 0;
}
