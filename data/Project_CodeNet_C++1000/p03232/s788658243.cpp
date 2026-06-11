
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;


const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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


int main() {
	ll i, j, k, l, m, n, sum, flag, cc,N,M;
	sum = 0;
	flag = 0;
	cin >> N;
	vector<ll>A(N);
	REP(i, 0, N) {
		cin >> A[i];
	}
	vector<ll>sum1(N + 1);
	COMinit();
	REP(i, 0, N + 1) {
		sum1[i] = 0;
	}
	REP(i, 1, N + 1) {
		sum1[i] = sum1[i - 1] + inv[i];
		sum1[i] %= MOD;
	}
	vector<ll>com(N);
	REP(i, 0, N) {
		com[i] = sum1[i + 1] - 1 + sum1[N - i];
		com[i] %= MOD;
	}
	ll ans = 0;
	REP(i, 0, N) {
		ans += A[i] * com[i];
		ans %= MOD;
	}
	ans *= fac[N];
	ans %= MOD;
	output(ans);
	return 0;
}