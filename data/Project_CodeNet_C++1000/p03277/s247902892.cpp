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
ll vv[111111];
ll fin[111111];
ll ps[111111];
ll tree[444444];
ll lef, rig, mid, best, n, C;

ll query(ll l, ll r)
{
	ll ret=0;
	for(l+=C , r+=C ; l<r ; l>>=1, r>>=1)
	{
		if(l&1) ret+=tree[l++];
		if(r&1) ret+=tree[--r];
	}
	return ret;
}

void upd(ll loc, ll val)
{
	loc+=C; tree[loc]+=val;
	for( ; loc>1 ; loc>>=1) tree[loc>>1]=tree[loc]+tree[loc^1];
}

bool isok(ll x) // m_{l,r}>=x인 #[l,r] * 2 >= (n+1)C2
{
	int i; ll ret=0; C=2*n+4;
	for(i=0 ; i<=444400 ; i++) tree[i]=0;
	for(i=0 ; i<=n ; i++) ps[i]=0;
	for(i=1 ; i<=n ; i++)
	{
		if(vv[i]>=x) fin[i]=1;
		else fin[i]=-1; 
	}
	for(i=1 ; i<=n ; i++) ps[i]=ps[i-1]+fin[i];
	for(i=0 ; i<=n ; i++) ps[i]+=n;
	for(i=0 ; i<=n ; i++)
	{
		ret+=query(0,ps[i]+1);
		upd(ps[i],1);
	}
	if(2*ret>=(n+1)*n/2) return true;
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n; int i;
	for(i=1 ; i<=n ; i++) cin>>vv[i];
	lef=1; rig=1e9+7;
	while(lef<=rig)
	{
		mid=(lef+rig)/2;
		if(isok(mid)) best=mid, lef=mid+1;
		else rig=mid-1;
	}
	cout<<best; return 0;
}



// 제출하기 전에 생각햇나요?
// it may be easier/harder than you think
// ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);