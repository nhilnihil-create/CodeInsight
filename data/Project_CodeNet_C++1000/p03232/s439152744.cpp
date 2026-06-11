#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int p[maxn],co[maxn];
int a[maxn];

int ppow(int x,int y)
{
    if (y==0) return 1;
    int ret=ppow(x,y/2);
    ret=ret*ret%mod;
    if (y&1) ret=ret*x%mod;
    return ret;
}

int32_t main()
{
    IOS
    int n;
    cin>>n;
    p[0]=1;
    for (int i=1;i<=n;i++) p[i]=p[i-1]*i%mod;
    for (int i=1;i<=n-1;i++)
    {
        co[i]=p[n]*ppow(i+1,mod-2)%mod;
        co[i]=(co[i-1]+co[i])%mod;
    }

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans=(ans+a[i]*p[n])%mod;
        ans=(ans+a[i]*co[i-1])%mod;
        ans=(ans+a[i]*co[n-i])%mod;
    }
    cout<<ans<<endl;
}

