#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
const ld PI=3.14159265358979;
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}

ll dp[100105];
bool cmp(pair<ppl,ll> &a,pair<ppl,ll> &b)
{
    return (a.F.F+a.F.S)<(b.F.F+b.F.S);
}
int main()
{
    IOS
    ll n;
    cin>>n;
    vector<pair<ppl,ll>> v(n+1);

    for(int i=1;i<=n;i++)
        cin>>v[i].F.F>>v[i].F.S>>v[i].S;
    sort(all(v),cmp);
    
    //dp[i]=max score for weight i 
    ll maxS=100100;
    for(int i=1;i<=n;i++)
    {   
        for(int w=min(v[i].F.S,maxS-v[i].F.F);w>=0;w--)
        {
            dp[w+v[i].F.F]=max(dp[w+v[i].F.F],dp[w]+v[i].S);
        }
    }
    ll ans=0;
    for(int i=0;i<=maxS;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;  
}