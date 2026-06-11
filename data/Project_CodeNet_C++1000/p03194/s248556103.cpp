#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<typename T>
map<T,ll> factorize(T x){
	map<T,ll> res;
	for(ll i=2;i*i<=x;i++){
		while(x%i==0){
			x/=i;
			res[i]++;
		}
	}
	if(x!=1) res[x]++;
	return res;
}
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a ;
        a = a * a;
        n >>= 1;
    }
    return res;
}
int main(){
ll n,p;
cin>>n>>p;
map<ll,ll> mp=factorize(p);
ll ans=1;
for(auto p:mp){
       if(p.se/n)ans*=modpow(p.fi,p.se/n);
}
cout<<ans<<endl;
}
