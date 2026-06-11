#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

const int MAX_N = (3e+5)+10;
vec nCm(MAX_N+1,0);
vec fact(MAX_N+1,0),fact_inv(MAX_N+1,0);

ll fastpow(ll a, ll pw) {
	ll res = 1;
	while (pw) {
		if (pw & 1) res = res * a % MOD;
		a = a * a % MOD;
		pw >>= 1;
	}
	return res;
}
void makefact(ll n){//MODは素数かつnより大きい
    ll ans = 1;
    fact.at(0) = ans;
    fact_inv.at(0) = ans;
    reps(i,1,n+1){
        (ans *= i)%=MOD;
        fact.at(i) = ans;
        fact_inv.at(i) = fastpow(ans,MOD-2);
    }
    return;
}
void makenCm(ll n){
    rep(i,n+1){
        ll ans = fact.at(n);
        (((ans*=fact_inv.at(n-i))%=MOD)*=fact_inv.at(i))%=MOD;
        nCm.at(i) = ans;
    }
    return;
}


int main() {
    cin>>N>>A>>B>>K;
    makefact(N+10);
    makenCm(N);
    ll ans = 0;
    rep(i,N+1){
        if((K >= A*i) && ((K - A*i)%B == 0) && ((K - A*i)/B <= N)) (ans += (nCm.at(i) * nCm.at((K - A*i)/B))%MOD)%=MOD;
    }
    cout<<ans<<endl;
}