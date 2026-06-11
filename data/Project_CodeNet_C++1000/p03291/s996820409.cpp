#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{ return firstElof.second < secondElof.second; }
//**Snippetリスト**//
//rep, vin, all//
//gcdlcm, isPrime, eratos, modinv, bitSearch, bitList, dfs, bfs, dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l, m, n; ll N, M, K, H, W, L; 
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 0;
vl flag, color; vll path; vl D;
//***********//
int main() {
	string S;
	cin >> S;
	N = S.length();
	vl A, B, C, D;
	vl sumA(N + 1), sumB(N + 1), sumC(N + 1), sumD(N + 1);
	sumA[0] = 0; sumB[0] = 0; sumC[0] = 0; sumD[0] = 0;
	for (i = 0; i < N; i++) {
		if (S[i] == 'A') {
			A.push_back(i);
			sumA[i + 1] = sumA[i] + 1; sumB[i + 1] = sumB[i]; sumC[i + 1] = sumC[i]; sumD[i + 1] = sumD[i];
		}
		else if (S[i] == 'B') {
			B.push_back(i);
			sumA[i + 1] = sumA[i]; sumB[i + 1] = sumB[i] + 1; sumC[i + 1] = sumC[i]; sumD[i + 1] = sumD[i];
		}
		else if (S[i] == 'C') {
			C.push_back(i);
			sumA[i + 1] = sumA[i]; sumB[i + 1] = sumB[i]; sumC[i + 1] = sumC[i] + 1; sumD[i + 1] = sumD[i];
		}
		else if (S[i] == '?') {
			D.push_back(i);
			sumA[i + 1] = sumA[i]; sumB[i + 1] = sumB[i]; sumC[i + 1] = sumC[i]; sumD[i + 1] = sumD[i] + 1;
		}
	}
	//3^Qをあらかじめ前計算
	vl Q(N + 1); Q[0] = 1;
	for (i = 0; i < N; i++) {
		Q[i + 1] = (Q[i] * 3) % MOD;
	}
	//元からあるBをBとして用いた
	for (i = 0; i < B.size(); i++) {
		ll aa = sumA[B[i]];
		ll da = sumD[B[i]];
		ll cc = sumC[N] - sumC[B[i] + 1];
		ll dc = sumD[N] - sumD[B[i] + 1];
		//qaは3^(da-1)のこと
		ll a;
		if (da == 0) a = aa % MOD;
		else a = (aa * Q[da] + da * Q[da - 1]) % MOD;
		ll c;
		if (dc == 0) c = cc % MOD;
		else c = (cc * Q[dc] + dc * Q[dc - 1]) % MOD;
		ans = (ans + a * c) % MOD;
		//cout << ans << endl;
	}
	//?をBとして用いた
	for (i = 0; i < D.size(); i++) {
		ll aa = sumA[D[i]];
		ll da = sumD[D[i]];
		ll cc = sumC[N] - sumC[D[i] + 1];
		ll dc = sumD[N] - sumD[D[i] + 1];
		//qaは3^(da-1)のこと
		ll a;
		if (da == 0) a = aa % MOD;
		else a = (aa * Q[da] + da * Q[da-1]) % MOD;
		ll c;
		if (dc == 0) c = cc % MOD;
		else c = (cc * Q[dc] + dc * Q[dc-1]) % MOD;
		ans = (ans + a * c) % MOD;
		//cout << ans << endl;
	}
	cout << ans;
}
	
