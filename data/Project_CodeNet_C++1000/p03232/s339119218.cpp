#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e5+7;
const int mod=1e9+7;
LL sum[maxn],a[maxn];

LL ksm(LL a,LL b)
{
    LL res=1,base=a;
    while (b)
    {
        if (b&1) res=MOD(res*base);
        base=MOD(base*base);
        b/=2;
    }
    return (res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;for (int i=1;i<=n;i++) cin>>a[i];
    sum[1]=1;for (int i=2;i<=n;i++) sum[i]=MOD(ksm(i,mod-2)+sum[i-1]);
    LL ans=0;
    for (int i=1;i<=n;i++)
    {
        ans=MOD(ans+(sum[n-i+1]+sum[i]-1)*a[i]);
    }
    LL tmp=1;for (int i=1;i<=n;i++) tmp=MOD(tmp*i);
    ans=MOD(ans*tmp);
    cout<<ans;
    return 0;
}
