#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define io std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const double pi=acos(-1);
const ll P = 998244353, INF = 0x3f3f3f3f;
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
const double eps=1e-5;
const ll maxn=2e3+10;
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int n,k,q;
ll a[maxn];
ll solve(int  x)
{
    vector<ll> ans;
    ll t=a[x];
    vector<ll> anss;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<t)
        {
            sort(ans.begin(),ans.end());
            int len=ans.size()-k+1;
            for(int j=0; j<len; j++)
            {
                anss.push_back(ans[j]);
            }
            ans.clear();
        }
        else
            ans.push_back(a[i]);
    }
    sort(ans.begin(),ans.end());
    int len=ans.size()-k+1;
    for(int j=0; j<len; j++)
    {
        anss.push_back(ans[j]);
    }
    sort(anss.begin(),anss.end());
    if(anss.size()<q)
    return -1;
    return  anss[q-1]-t;
}
int main()
{
    cin>>n>>k>>q;
    ll ans=1e18;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        ll t=solve(i);
        if(t==-1)continue;
        ans=min(t,ans);
    }
    cout<<ans<<endl;
}
