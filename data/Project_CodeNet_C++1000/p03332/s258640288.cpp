#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define mp make_pair
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const long long MXN = 3e5 + 1;
const long long MNN = 1e3 + 1;
const long long MOD = 998244353;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, a, b, k, ans, f[MXN];

llong binpow(llong a, llong b){
	if(b == 0){
		return 1;
	}if(b % 2 == 1) return (binpow(a, b - 1) * a) % MOD;
	else{
		llong x = binpow(a, b / 2);
		return (x * x) % MOD;
	}
}

llong C(llong n, llong k){
	llong x = (f[k] * f[n - k]) % MOD;
	return (f[n] * binpow(x, MOD - 2)) % MOD;
}

llong solve(llong cntA, llong cntB){
//	llong ans = 0;
//	for(int i = min(cntA, cntB); i >= 0; i--){
//		llong R = cntA - i, B = cntB - i, G = i;
//		if(R + G + B > n) break;
//		ans += (((C(n, R) * C(n - R, B)) % MOD) * C(n - R - B, G)) % MOD;
//		ans %= MOD;
//	}
//	return ans;
        if (cntB > n) return 0;
	return C(n, cntA) * C(n, cntB) % MOD;
}

int main(){
	ios;
	f[0] = 1;
	for(int i = 1; i < MXN; i++){
		f[i] = (f[i - 1] * i) % MOD;
	}
	cin >> n >> a >> b >> k;
	for(int i = 0; i <= n; i++){
		if(k >= a * i && (k - (i * a)) % b == 0){
			ans += solve(i, (k - (i * a)) / b);
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}
// 6391049189 - 48090 * 33447
