#include <bits/stdc++.h>
using namespace std;
const int maxn=112345;
int n,m,l,r,x,f[maxn],d[maxn];
int F(int x) {
    if (x==f[x]) return x;
    int fa=f[x];
    f[x]=F(f[x]);
    d[x]+=d[fa];
    return f[x];
}
inline bool U(int a,int b,int l) {
    int fa=F(a),fb=F(b);
    if (fa==fb) {
        if (d[b]-d[a]!=l) return false;
        return true;
    }
    d[fa]=-d[a]+d[b]-l;
    f[fa]=fb;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) f[i]=i;
    for (int i=1;i<=m;++i) {
        scanf("%d%d%d",&l,&r,&x);
        if (!U(r,l,x)) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
