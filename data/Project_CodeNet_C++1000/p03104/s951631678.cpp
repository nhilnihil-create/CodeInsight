#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MAX 510000
#define rrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define dcout cout<<fixed<<setprecision(15);

using namespace std;
typedef long long int  ll;
typedef pair<int, int> P;

constexpr int MOD = 1e9 + 7;
constexpr ll inf = 1LL << 60;

//lcm//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//a^n mod p//
ll modpow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;
  ll t = modpow(a, n / 2, p);
  return (t * t) % p;
}

//inversemod//
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

//Cmonp//
ll fac[MAX], finv[MAX], inv[MAX];
// 
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 
ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//LARGE n
ll com(ll n,ll m){
    if(n<m || n<=0 ||m<0){
		return 0;
	}
	if( m==0 || n==m){
		return 1;
	}
	ll k=1;
	for(ll i=1;i<=m;i++){
       k*=(n-i+1); 
	   k%=MOD;
	   k*=modinv(i,MOD);
	   k%=MOD;
	}
	return k;
}

//radP
ll rad(ll u, ll p){
ll cnt=0;
	while(u%p==0){
		u/=p;
		cnt++;
	}
	return cnt;
}


////////////////////////////////////////////////////////////////////


int main() {

ll a,b;
cin>>a>>b;
if(a==b){cout<<a<<endl;
return 0;}

ll ans=0;

ll k;
if(a%2==0 && b%2==0){
if((b/2-a/2)%2)k=1;
else k=0;
}
if(a%2==0 && b%2){
if((b/2-a/2+1)%2)k=1;
else k=0;
}
if(a%2 && b%2==0){
	if((b/2-a/2)%2) k=1;
	else k=0;
}
if(a%2 && b%2){
	if((b/2-a/2+1)%2) k=1;
	else k=0;
}
ans+=k;



ll v=1;
for(ll i=1;i<=48;i++){
v*=2;
ll s=0;
if(a>=v){
	ll aa=a-v;
	aa%=v;
	if(a%(v*2)>=v)
s-=aa;
}
if(b>=v){
	ll bb=b-v;
	bb%=v;
	if(b%(v*2)>=v)
	s-=(v-bb-1);
}

if((s+inf)%2) ans+=v;
}

cout<<ans<<endl;

}
