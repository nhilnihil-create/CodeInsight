#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define int long long

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

const ll MOD = 998244353LL;

long long mod_inverse(long long x) {
	long  long ret = 1; long long n = MOD - 2;
	while (n) {
		if (n & 1)ret = ret * x%MOD;
		x = x * x%MOD; n >>= 1;
	}
	return ret;
}

ll fact[300300], fact_inv[300300];

ll comb(ll n, ll r) {
	ll ret = ((fact[n] * fact_inv[n - r]) % MOD )* fact_inv[r] % MOD;
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll N, A, B, K; cin >> N >> A >> B >> K;
	fact[0] = 1LL; fact_inv[0] = mod_inverse(1LL);
	rep(i, N) {
		fact[i + 1] = fact[i] * (i + 1) % MOD;
		fact_inv[i + 1] = mod_inverse(fact[i + 1]);
	}
	ll ans = 0;
	rep(a, N + 1) {
		ll K_ = K - a * A;

		if(K_ % B != 0) continue;
		ll b = K_ / B;
		if(b < 0 || N < b) continue;
		ans += comb(N, a) * comb(N, b) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}