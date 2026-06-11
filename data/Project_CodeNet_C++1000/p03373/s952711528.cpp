#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n;i>=a;--i)
#define pb push_back
#define fi first
#define se second
#define io std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll qpow(ll a,ll n)
{
    ll r=1%P;
    for (a%=P; n; a=a*a%P,n>>=1)if(n&1)r=r*a%P;
    return r;
}
int main()
{
    int x,y;
    int a,b,c;
    cin>>a>>b>>c>>x>>y;
    if(x>y)
        {
            swap(x,y);
            swap(a,b);
        }
    int ans=0;
    if(2*c<a+b)
    {
        ans+=2*c*x;
        y-=x;
        x=0;
    }
    if(2*c<a)
        a=2*c;
    if(2*c<b)b=2*c;
    ans+=a*x+b*y;
    cout<<ans<<endl;
}
