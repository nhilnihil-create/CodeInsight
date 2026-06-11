
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define m0(x) memset(x,0,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))

using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };




ll gcd(ll x, ll y) {
	ll m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}

ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

long long nCr(int n, int r) {
	if (r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}

	return ans;
}


const int MOD = 1000000007;
const int MAX = 100010;


ll inv[MAX];//逆元
void makeInv() {
	inv[1] = 1;
	FOR(i, 2, MAX) {
		inv[i]= MOD - inv[MOD%i] * (MOD / i) % MOD;
	}
}

//階乗のmod
ll FactMod(int n, int m) {
	ll x = 1;
	FOR(i, 1, n + 1) {
		x *= i;
		x %= m;
	}
	return x;
}

ll cum[MAX];//累積和
ll Ex[MAX];//ブロックiのコストがかかる回数の期待値
ll A[MAX];

int main() {

	int N; cin >> N;
	FOR(i,1, N+1) {
		cin >> A[i];
	}

	makeInv();
	ll fact = FactMod(N, MOD);

	cum[0] = 0;
	cum[1] = 1;
	FOR(i, 2, MAX) {
		cum[i] = (cum[i - 1] + inv[i]) % MOD;
	}

	FOR(i,1, N + 1) {
		Ex[i] = cum[i] - cum[0] + cum[N - i + 1] - cum[1];
		Ex[i] %= MOD;
	}

	ll ans = 0;
	FOR(i, 1, N + 1) {
		ans += Ex[i] * A[i];
		ans %= MOD;
	}
	ans *= fact;
	ans %= MOD;

	cout << ans << endl;
}


