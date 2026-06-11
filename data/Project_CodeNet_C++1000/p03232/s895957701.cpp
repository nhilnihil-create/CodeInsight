#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

ll fastpow(ll a, ll pw) {
	ll res = 1;
	while (pw) {
		if (pw & 1) res = res * a % MOD;
		a = a * a % MOD;
		pw >>= 1;
	}
	return res;
}
int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    vec inv_n(N + 1, 1);
    ll temp = 0, ans = 0, factN = 1;
    reps(i, 1, N + 1) (factN *= i)%=MOD;
    reps(i,1,N+1) {
        inv_n[i] = (factN * fastpow(i, MOD - 2))%MOD;
        (temp += inv_n[i])%=MOD;
    }
    rep(i,N){
        (ans += (temp * a[i])%MOD)%=MOD;
        if(i != N - 1) (temp += MOD - inv_n[N - i] + inv_n[i + 2])%=MOD;
    }
    cout<<ans<<endl;
}