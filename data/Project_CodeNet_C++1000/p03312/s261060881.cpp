#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <complex>
#include <iomanip>
#include <stack>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
ll mod=1e9+7;
double eps=1e-7;
ll exp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=(x*x)%mod){if(y&1)ret=(ret*x)%mod;}return ret;}
ull pexp(ull x,ull y){if(y<0) return 0; ull ret=1; for(;y;y>>=1,x=(x*x)){if(y&1)ret=(ret*x);}return ret;}
ll gcd(ll x,ll y){if(!x||!y) return x+y; return x%y==0?y:gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll bsum(ll u,ll b){ll ret=0;if(u<b)return u;while(u){ret+=u%b;u/=b;}return ret;}
ll prival(ll u,ll p){ll cn=0;while(u%p==0){cn++;u=u/p;}return cn;}
ll minv(ll a,ll b){return 1<a?b-minv(b%a,a)*b/a:1;}
ll extm(ll a,ll b){ll ret=0;while(a!=0){if(a%2==1){ret+=b;ret%=mod;}a>>=1;b=(2*b)%mod;}return ret;}   
ll eaphi(ll x){ll t=x,ret=x,i;for(i=2;i*i<=x;i++){if(t%i==0){ret-=ret/i;while(t%i==0) t/=i;}}if(t!=1) ret-=ret/t;return ret;}
ll eadivc(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=2;if(x%i==0 && i*i==x) ret+=1;}return ret;}
ll eadivs(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=i+x/i;if(x%i==0 && i*i==x) ret+=i;}return ret;}
ll ndig(ll x, ll b){ll ret=0;while(x){x/=b; ret++;}return ret;}
ll rev(ll n, ll b){ll ret=0;while(n){ret=b*ret+n%b; n/=b;}return ret;}
ll sq(ll x){ll t=(ll)sqrt(x); for(ll i=t-2 ; i<=t+2 ; i++) if(i*i==x) return abs(i); return -1;}
ll extexp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=extm(x,x)){if(y&1)ret=extm(ret,x);}return ret;}
bool isprime(ll x){if(x<=1) return false; for(ll i=2;i*i<=x;i++){if(x%i==0){return false;}}return true;}
ll n, ans=1e18;
ll a[222222], ps[222222];

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n; int i, j, loc;
	for(i=1 ; i<=n ; i++) cin>>a[i];
	for(i=1 ; i<=n ; i++) ps[i]=ps[i-1]+a[i];
	for(i=2 ; i<=n-2 ; i++) // make a cut [right of i] 
	{
		loc=lower_bound(ps+1,ps+n+1,ps[i]/2)-ps;
		ll tt_1=0, tt_2=0, cc_1, cc_2;
		for(j=loc-3 ; j<=loc+3 ; j++)
		{
			if(j<=0 || j>=i) continue;
			if(min(ps[i]-ps[j],ps[j])>tt_1) cc_1=j, tt_1=min(ps[i]-ps[j],ps[j]);
		}
		loc=lower_bound(ps+1,ps+n+1,ps[i]+(ps[n]-ps[i])/2)-ps;
		for(j=loc-3 ; j<=loc+3 ; j++)
		{
			if(j<=i || j>=n) continue;
			if(min(ps[n]-ps[j],ps[j]-ps[i])>tt_2) cc_2=j, tt_2=min(ps[n]-ps[j],ps[j]-ps[i]);
		}
		ll v=max(max(ps[i]-ps[cc_1],ps[cc_1]),max(ps[n]-ps[cc_2],ps[cc_2]-ps[i]))-min(min(ps[i]-ps[cc_1],ps[cc_1]),min(ps[n]-ps[cc_2],ps[cc_2]-ps[i]));
		ans=min(ans,v);
	}
	cout<<ans; return 0;
}

// 제출하기 전에 생각햇나요?
// it may be easier/harder than you think
// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);