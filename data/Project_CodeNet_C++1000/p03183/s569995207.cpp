#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct stone{
    
    int w,s;ll v;
}a[1005];
int n;ll f[20005],ans;
bool cmp(stone x,stone y){return x.w+x.s<y.w+y.s;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%lld",&a[i].w,&a[i].s,&a[i].v);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    for(int j=a[i].s;j>=0;j--)
    f[j+a[i].w]=max(f[j+a[i].w],f[j]+a[i].v);
    for(int i=0;i<20001;i++) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}