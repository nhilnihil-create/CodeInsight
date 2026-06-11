#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
typedef long long int LL;
using namespace std;
LL N,M,fa[100010],sizes[100010],res,cnt[100010]= {0},a[100010],b[100010];
void init()
{
    for(int i=1; i<=N; i++)
    {
        fa[i]=i;
        sizes[i]=1;
    }
}
int finds(int x)
{
    if(fa[x]==x)
        return x;
    else
        return fa[x]=finds(fa[x]);
}
int main()
{
    scanf("%lld%lld",&N,&M);
    init();
    for(int i=1; i<=M; i++)
        scanf("%lld%lld",&a[i],&b[i]);
    res=N*(N-1)/2;
    for(int i=M; i>0; i--)
    {
        cnt[i]=res;
        int x=finds(a[i]),y=finds(b[i]);
        if(x!=y)
        {
            fa[y]=x;
            res-=sizes[x]*sizes[y];
            sizes[x]+=sizes[y];
        }
    }
    for(int i=1; i<=M; i++)
        printf("%lld\n",cnt[i]);
    return 0;
}