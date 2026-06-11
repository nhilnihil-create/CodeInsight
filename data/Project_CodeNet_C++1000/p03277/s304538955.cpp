#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
char tmp;
int read()
{
    int f(1),x(0);
    for(tmp=getchar();!isdigit(tmp);tmp=getchar()) if(tmp=='-') f=-1;
    for(;isdigit(tmp);tmp=getchar()) x=x*10+tmp-'0';
    return f*x;
}
long long limit,ans;
int n,arr[100010],cnt[1000100],treearr[1000100];
inline int lowbit(const int & k)
{
    return k&(-k);
}
void update(int x)
{
    while(x<=200050)
    {
        treearr[x]++;
        x+=lowbit(x);
    }
}
long long query(int x)
{
    long long r=0;
    while(x)
    {
        r+=treearr[x];
        x-=lowbit(x);
    }
    return r;
}

bool check(const int & mid)
{
    ans=0; memset(treearr,0,sizeof(treearr));
    for(int i=1;i<=n;i++)
        cnt[i]=cnt[i-1]+((arr[i]<mid)?(-1):1);
    for(int i=0;i<=n;i++)
    {
        ans+=query(cnt[i]+100010);
        update(cnt[i]+100010);
    }
    return ans>=(long long) n*(n+1)/4;
}

int main()
{
    int l=0,r=0,mid;
    n=read();
    for(int i=1;i<=n;i++)
    {
        arr[i]=read();
        r=max(r,arr[i]);
    }
    limit=(n+1)*n/4;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}
