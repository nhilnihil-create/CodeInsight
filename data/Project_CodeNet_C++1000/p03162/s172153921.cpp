#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define nl '\n'
#define vec vector<ll>
#define pr pair<ll,ll>
#define vecp vector< pr >
#define pq priority_queue<ll>
#define pqp priority_queue<pr>
#define ff first
#define ss second
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fa(x,v) for(auto x:v)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define PI 3.14159265
 const ll MOD=1000000007;
 ll powerm(ll a, ll b, ll MOD) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll power(ll a, ll b) {

  ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}
ll binarySearch(ll a[],ll low,ll high,ll key){
    while(low<=high)
    {
        ll mid=low+((high-low)/2);
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
ll gcd(ll a, ll b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
vec sieve;
void Sieve(int N) {
    const ll maxn = N+1;
    sieve.resize(maxn);
    f(i,0,maxn) sieve[i] = i;
    sieve[1] = -1;
    sieve[0] = -1;
    f(i, 2, maxn) if (i == sieve[i]) for (ll j = 2 * i ; j < maxn ; j += i) if (sieve[j] == j) sieve[j] = i;
}
ll dp[100001][4];
ll rec(ll n,ll*a,ll*b,ll*c)
{
dp[1][1]=a[1];
dp[1][2]=b[1];
dp[1][3]=c[1];
for(ll i=2;i<=n;i++)
{
	dp[i][1]=a[i]+max(dp[i-1][2],dp[i-1][3]);
	dp[i][2]=b[i]+max(dp[i-1][1],dp[i-1][3]);
	dp[i][3]=c[i]+max(dp[i-1][1],dp[i-1][2]);
}
return max3(dp[n][1],dp[n][2],dp[n][3]);
	
}
int main()
{
	fast
ll n;
cin>>n;
ll a[n+1],b[n+1],c[n+1];
f(i,1,n+1)
cin>>a[i]>>b[i]>>c[i];
ll ans=rec(n,a,b,c);
cout<<ans<<nl;
return 0;
}