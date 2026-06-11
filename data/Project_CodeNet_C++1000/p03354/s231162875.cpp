#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 25, M = 1e6 + 25, oo = 1e9+7, mxmsk = 1 << 16;
const long long OO = 1e18+25;
    
#define f first
#define s second
    
int n,m,a[N], x,y, dsu[N], cnt;
    
int findparent(int u)
{
    if(u == dsu[u]) return u;
    return dsu[u] = findparent(dsu[u]);
}

void merge(int u, int v)
{
    u = findparent(u);
    v = findparent(v);
    dsu[u] = v;
}
    
int main() {
    iota(dsu, dsu+N, 0);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n ; i++) scanf("%d",a+i);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        merge(x,y);
    }
    for(int i=1; i<=n; i++)
    {
        cnt += (findparent(i) == findparent(a[i]));
    }
    printf("%d",cnt);
    return 0;
}