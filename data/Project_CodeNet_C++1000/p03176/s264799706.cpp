#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#define inputarr(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define prllarr(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" ";
#define pb push_back
#define ll long long
#define mod 1000000007
#define foi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define in(n) scanf("%lld",&n);
#define in2(x,y) scanf("%lld %lld",&(x),&(y));
#define in3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define out(n) printf("%lld\n",n);
#define out2(x,y) printf("%lld %lld\n",x,y);
#define test(t)  ll t; in(t);while(t--)
#define set(arr,n,s) for(ll i=0;i<n;i++){arr[i]=s;}


ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1){res=(res*x)%p;} y=y>>1;x=(x*x)%p;}return res;}
ll modInverse(ll a,ll p){return power(a,p-2,p);}//used with feemat little

ll gcd(ll x,ll y){if(x==0 || y==0){return max(y,x);}return gcd(y%x,x);}
ll gcdExtended(ll a,ll b,ll &x,ll &y){if(a==0){x=0;y=1;return b;}ll x1,y1;ll gcd = gcdExtended(b%a,a,x1,y1);x=y1-(b/a)*x1;y=x1;return gcd;}//o(log(b))
;
void prac(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   #endif 
}
ll maxi=200003;
ll bit[200005];
pair<ll,ll> h[200005];
ll get(ll i){
	ll ans=0;
	for(;i;i-=(i&(-i)))ans=max(ans,bit[i]);
	return  ans;
}
void update(ll i,ll val){
	for(;i<=maxi;i+=(i&(-i)))bit[i]=max(bit[i],val);
}
ll dp[200005];


int main() 
{
  	// prac();
  	ll n;
  	in(n)
  	for(ll i=1;i<=n;i++){
  		in(h[i].first)
  	}
  	for(ll i=1;i<=n;i++){
  		in(h[i].second)
  	}
  	for(ll i=0;i<=maxi;i++)bit[i]=0;
  	
  	ll ans=0;
  	for(ll i=1;i<=n;i++){
  		ll hei=h[i].first;
  		hei--;
  		dp[i]=get(hei)+h[i].second;
  		update(h[i].first,dp[i]);
  		ans=max(dp[i],ans);

  	}
  	out(ans);



}
/*error-----
convert every int to long long eg-1LL
create array with proper analysis of problem constrain
check mod also
*/




