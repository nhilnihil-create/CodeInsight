#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll M=1e9+7;
const ll MAXN=1e6+7;
const ld pi=acos(-1);

#define gi(n) ll n=read()
#define endl '\n'
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define per(i,a,b) for(ll i=b-1; i>=a; --i)

typedef vector<ll> V;
typedef vector<V> VV;
typedef set<ll> S;
typedef pair<ll,ll> pl;
typedef vector<pl> Vp;

#define all(v) v.begin(),v.end()
#define pb push_back
#define fs first
#define sc second

inline ll read(){
	ll x=0,ff=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') ff=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*ff;
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll pow1(ll p,ll d, ll P){return d?(pow1(p*p%P,d>>1,P)*(d&1?p:1))%P:1;}

V prime;
bool is_composite[MAXN];
void sieve (ll n){
	std::fill (is_composite, is_composite + n, false);
	rep(i,2,n){
		if(!is_composite[i]) prime.pb(i);
		for(ll j = 0; j < prime.size() && i*prime[j] < n; ++j){
			is_composite[i*prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
ll modInverse(ll a, ll m){
	ll m0=m,y=0,x=1;
	if(m==1) return 0;
	while(a>1){
		ll q=a/m,t=m;
		m=a%m;
		a=t; 
		t=y;

		y = x-q*y; 
		x = t;
	}
	if(x<0) x += m0;
	return x; 
}

ll f(ll a,ll b){return (a/b)*(b/2)+max(a%b-b/2+1,0LL);}

void doit(){
	gi(a); gi(b);
	V v;
	ll c=2,p=1,ans=0;
	for(;c/2<=b;c*=2)v.pb(f(b,c)-f(a-1,c));
	for(auto i:v) ans+=(i&1?1:0)*p, p*=2;
	cout<<ans;
}
int main(){
//	for(gi(t);t--;cout<<endl)
		doit();
	return 0;
}