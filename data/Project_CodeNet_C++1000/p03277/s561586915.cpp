# include <cstdio>
# include <cstring>
# include <iostream>
# define R register int
# define ll long long

using namespace std;

const int maxn=100005;
int n;
int a[maxn],m,l,r,mid,ans,c[maxn],t[maxn<<1];

void ins (int x) { for (R i=x;i<=2*n+2;i+=(i&(-i))) t[i]++; }
int ask (int x) { int ans=0; for (R i=x;i;i-=(i&(-i))) ans+=t[i]; return ans; }

bool check (int ans)
{
    ll cnt=0;
    memset(t,0,sizeof(t));
    for (R i=1;i<=n;++i)
        if(a[i]<=ans) c[i]=c[i-1]+1;
        else c[i]=c[i-1]-1;
    ins(n+1);
    for (R i=1;i<=n;++i)
    {
        cnt+=ask(c[i]+n);
        ins(c[i]+n+1);
    }
    ll b=1LL*n*(n+1)/2;
    b/=2;
    return cnt>=b+1;
}

int main()
{
    scanf("%d",&n);
    for (R i=1;i<=n;++i)
        scanf("%d",&a[i]),m=max(m,a[i]);
    l=0,r=m,ans=m;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            ans=min(ans,mid),r=mid-1;
        else
            l=mid+1;
    }
    printf("%d",ans);
    return 0;
}
