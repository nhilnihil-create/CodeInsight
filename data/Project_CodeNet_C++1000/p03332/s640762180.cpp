#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 998244353
#define mo 998244353
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

ll comb(ll N_, ll C_) {
	const int NUM_ = 400001;
	static ll fact[400002], factr[400002], inv[400002];
	if (fact[0] == 0) {
		inv[1] = fact[0] = factr[0] = 1;
		for (int i = 2; i <= NUM_; ++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i = 1; i <= NUM_; ++i) fact[i] = fact[i - 1] * i%mo, factr[i] = factr[i - 1] * inv[i] % mo;
	}
	if (C_<0 || C_>N_) return 0;
	return factr[C_] * fact[N_] % mo*factr[N_ - C_] % mo;
}
ll modpow(ll a, ll n = mo - 2) {
	ll r = 1;
	while (n) r = r * ((n % 2) ? a : 1) % mo, a = a * a%mo, n >>= 1;
	return r;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, A, B, K;
	cin >> N >> A >> B >> K;

	int ans = 0;
	eFOR(i, 0, N) {
		double y = (double)(K - A * i) / B;
		int a;
		if (y < 0)continue;
		
		if (ceil(y) == floor(y)) {
			a = y;
			ans += comb(N, i)*comb(N, a);
			ans %= mod;
			
		}
	}

	cout << ans << endl;
	return 0;
}

