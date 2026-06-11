#include<bits/stdc++.h>
using namespace std;
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define F first
#define S second	
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define LCM(a,b) (a*b)/__gcd(a,b)
#define mii map<int,int>
#define mll map<ll,ll>
#define ub upper_bound
#define lb lower_bound
#define sz(x) (ll)x.size()
#define ld long double
#define pcnt(x) __builtin_popcountll(x)
const long long I1=1e9;
const long long I2=1e18;
const int32_t M1=1e9+7;
const int32_t M2=998244353;
template<typename T,typename T1>T maxn(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T minn(T &a,T1 b){if(b<a)a=b;return a;}

void solve()
{
  //code begins from here//
 ll n,k;
 cin>>n>>k;
 ll a[n+1];
 ll dp[k+1]={0};
 lop1(i,n) {cin>>a[i];dp[a[i]]=1;}
 lop1(i,k)
 {
     if(dp[i]==1) continue;
     dp[i]=2;
     lop1(j,n)
     {
        if (i+a[j]<=k) dp[i+a[j]]=1;
     }
 }
 cout<<(dp[k]==1?"First":"Second")<<endl;
}

signed main()
{
    IOS;
    #ifdef MODULO
        initialize();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    int testcase=1;
    //cin>>testcase;
    while(testcase--) solve();
    return 0;
}