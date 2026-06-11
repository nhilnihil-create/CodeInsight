#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],b[N],c[N];
bool solve(int k)
{
    int t=1<<k;
    for(int i=1;i<=n;i++) c[i]=b[i]%(2*t);
    sort(c+1,c+1+n);
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        int x=a[i]%(2*t);
        int l=lower_bound(c+1,c+1+n,t-x)-c;
        int r=lower_bound(c+1,c+1+n,2*t-x)-c-1;
        if(l<=r)
            flag^=(r-l+1)&1;
        l=lower_bound(c+1,c+1+n,3*t-x)-c;
        r=lower_bound(c+1,c+1+n,4*t-x)-c-1;
        if(l<=r)
            flag^=(r-l+1)&1;
    }
    return flag;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    int ans=0;
    for(int i=0;i<=30;i++)
        if(solve(i))
        ans|=1<<i;
    printf("%d\n",ans);
}
