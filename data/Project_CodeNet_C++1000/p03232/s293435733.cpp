#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = ((B)-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl


//a^(p-1) = 1 (mod p)(p->Prime numbers)
//a^(p-2) = a^(-1)
ll calc(ll a,ll b,ll p){//a^(b) mod p   
	if(b==0)return 1;
	ll y = calc(a,b/2,p);y=(y*y)%p;
	if(b & 1) y = (y * a) % p;
	return y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll N;
	cin >> N;
	vector<ll> A(N);
	FOR(i,0,N)cin >> A[i];
	vector<ll> p(N+2,0),pa(N+1);
	FOR(i,1,N+1)p[i]=(p[i-1]+calc(i,MOD-2,MOD))%MOD;
	FOR(i,0,N)pa[i]=p[i+1]+p[N-i]-1;
	ll K=1;
	FOR(i,1,N+1)K=K*i%MOD;
	ll ans = 0;
	FOR(i,0,N){
		ll x = K * pa[i] % MOD;
		ans += x * A[i] % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}
