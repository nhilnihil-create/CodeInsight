#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

constexpr cat mod = 1000000007;

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e & 1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<cat> inv(N+1, 0);
	for(int i = 1; i <= N; i++) inv[i] = pw(i, mod-2);
	vector<cat> sum_inv(N+1, 0);
	for(int i = 2; i <= N; i++) {
		sum_inv[i] = sum_inv[i-1] + inv[i];
		if(sum_inv[i] >= mod) sum_inv[i] -= mod;
	}
	cat ans = 0;
	for(int i = 0; i < N; i++) ans += A[i] * (1 + sum_inv[i+1] + sum_inv[N-i]) % mod;
	ans %= mod;
	for(int i = 1; i <= N; i++) ans = ans * i % mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
