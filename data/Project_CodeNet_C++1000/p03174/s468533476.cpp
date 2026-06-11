#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
const lli INF = 1e9 + 100;
const lli INF64 = (1LL << 61) + 100;
const lli MOD = 1e9 + 7;
const lli MH1 = 1599614977, MH2 = 2034417103, MH3 = 1090250123, MH4 = 2024491871; 
const int N = 21;
lli dp[N][(1 << N)];
//dp[i][msk] - how many ways if we take 'i' mans and connect them with womans in 'msk'. bits(msk) = i. 
bool matrix[N][N];
lli bpow(lli baseee, lli exponenttt) {
	if(exponenttt < 0) return 0;
	lli res = 1;
	baseee %= MOD;
	while (exponenttt > 0) {
		if ((exponenttt & 1) == 1) res = (res*baseee) % MOD;
		baseee = (baseee*baseee) % MOD;
		exponenttt >>= 1;
	}
	return res;
}
lli multInverse(lli a) {//if_mod_is_prime
	return bpow(a, MOD - 2);
}
lli divm(lli a, lli b) {//if_mod_is_prime
	return (a * multInverse(b)) % MOD;
}
lli multm(lli a, lli b) {
	return (a * b) % MOD;
}
lli subm(lli a, lli b) {
	a += MOD;
	lli r = a - b;
	if(r >= MOD) return r - MOD;
	return r;
}
lli addm(lli a, lli b) {
	lli r = a + b;
	if(r >= MOD) return r - MOD;
	return r;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int inp;
			cin >> inp;
			matrix[i][j] = (inp ? 1 : 0);
		}
	}
	
	for(int i = 0; i < n; i++)
		for(int ii = 0; ii < n; ii++) 
			if(matrix[0][ii])
				dp[0][(1 << ii)] = 1;
	
	for(int i = 1; i < n; i++) {
		for(int msk = (1 << i)-1; msk < (1 << n); msk++) {
			if(__builtin_popcount(msk) != i+1) continue;
			for(int ii = 0; ii < n; ii++) {
				int prev = msk ^ (1 << ii); 
				if(matrix[i][ii] && prev < msk) 
					dp[i][msk] += dp[i-1][prev];
			}
			dp[i][msk] %= MOD;
		}
	}
	cout << dp[n-1][(1 << n) - 1] << "\n";
	return 0;
}