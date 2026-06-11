#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int>P;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 1010;
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//for(auto p:mp)(mapの探索)
//printf("%.10f\n",なんちゃら)
//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
ll dp[101010];

//union-find木について
ll par[101010];
ll rank2[101010];

void init(ll n) {
	rep(i, n) {
		par[i] = i;
		rank2[i] = 0;
	}
}

ll find(ll x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank2[x] < rank2[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank2[x] == rank2[y]) {
			rank2[x]++;
		}
	}
}

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

//long longしか使わない
//素数は1より大きい
int main() {
	ll n;
	cin >> n;
	vector<ll>a(n), b(n), c(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	rep(i, n) {
		cin >> c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	ll ans = 0;
	rep(i, n) {
		ll left = -1;
		ll right = n;
		while (right - left > 1) {
			ll mid = (left + right) / 2;
			if (a[mid] < b[i]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		ll left2 = -1;
		ll right2 = n;
		while (right2 - left2 > 1) {
			ll mid2 = (left2 + right2) / 2;
			if (c[mid2] <= b[i]) {
				left2 = mid2;
			}
			else {
				right2 = mid2;
			}
		}
		ans += right * (n - 1 - left2);
	}
	cout << ans << endl;
	return 0;
}
