#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 998244353;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template < typename T >
void vprint(T &v){
	REP(i, v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

const ll N_MAX = 400005;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];
void make(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll) i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}

ll Combination(ll C, ll D){
    if(C<D||C<1) return 0;
    return fac[C]*(finv[D]*finv[C-D]%mod)%mod;
}

int main(){
	ll N, A, B, K;
	cin >> N >> A >> B >> K;
	make();
	ll res = 0;
	REP(i, N+1){
		if((K-A*i)%B==0){
			ll j = (K-A*i)/B;
			if(j>=0&&j<=N)res += (Combination(N, i)*Combination(N, j)%mod);
			res %= mod;
		}
	}
	cout << res << endl;
    return 0;
}