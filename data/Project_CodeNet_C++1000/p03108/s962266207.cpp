#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,si[N],p[N],ans[N];
struct node
{
    int x,y;
}a[N];
ll find(ll x)
{
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}
void join(ll x,ll y)
{
    p[find(x)]=find(y);
}
ll get_sum(ll x)
{
    return x*(x-1)/2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        si[i]=1;
    }
    ll sum=0;
    ll rest=n*(n-1)/2;
    for(int i=m;i>=1;i--)
    {
        ans[i]=rest-sum;
        ll x=a[i].x;
        ll y=a[i].y;
        ll fx=find(x);
        ll fy=find(y);
        if(fx!=fy)
        {
            ll s1=get_sum(si[p[x]]);
            ll s2=get_sum(si[p[y]]);
            //printf("x=%lld y=%lld p[x]=%lld p[y]=%lld\n",x,y,p[x],p[y]);
            //printf("x块大小%lld y块大小%lld\n",si[p[x]],si[p[y]]);
            si[p[y]]+=si[p[x]];//x并到y上
            si[p[x]]=0;
            //printf("合并后的y块大小=%lld\n\n",si[p[y]]);
            ll s3=get_sum(si[p[y]]);
            join(x,y);
            ll tmp=s3-s1-s2;
            sum+=tmp;
            //printf("i=%d s1=%lld s2=%lld s3=%lld tmp=%lld sum=%lld\n",i,s1,s2,s3,tmp,sum);
        }
        //else sum++;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
