#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define MAX 1020000
#define rrep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define dcout cout<<fixed<<setprecision(15);
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int  ll;
typedef pair<ll, ll> P;

constexpr int MOD =1e9 + 7;
constexpr ll inf = 1LL << 60;

template< typename S, typename T >
inline void chmax(S &a, const T &b) { if(a < b) a = b; }
 
template< typename S, typename T >
inline void chmin(S &a, const T &b) { if(a > b) a = b; }
 

//lcm//
ll gcd(ll x, ll y) {
	if (x == 0) return y;
	return gcd(y%x, x);
}
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//a^n mod p//
ll modpow(ll a, ll n, ll p) {
	if(n==0) return (ll)1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;
  ll t = modpow(a, n / 2, p);
  return (t * t) % p;
}

//inversemod//
ll modinv(ll a, ll m) {
	if(m==0)return (ll)1;
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
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
ll n;
cin>>n;


ll v=0;
for(ll i=2;i<=10000;i++){
ll sum=i*(i-1)/2;
if(sum==n){
	v=i;
	break;
}
	if(sum>n){cout<<"No"<<endl;
	return 0;}
}

vector<ll> vec[v+1]{};

ll ind=1;
for(ll i=1;i<=v;i++){
	for(ll j=1;j<=v;j++){
if(i<j){vec[i].push_back(ind);
vec[j].push_back(ind);
ind++;}
	}
}

cout<<"Yes"<<endl;
cout<<v<<endl;
for(int i=1;i<=v;i++){
	cout<<vec[i].size()<<" ";
for(int j=0;j<vec[i].size()-1;j++){
	cout<<vec[i][j]<<" ";
}
cout<<vec[i][vec[i].size()-1]<<endl;
}


return 0;
}



