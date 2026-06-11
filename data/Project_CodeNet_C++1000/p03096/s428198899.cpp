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
#include <cstdio>
#include <tuple>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
void in() {}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop, bitSearch, bitList, nod//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv,  digitDP//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal ,RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q; ll A, B;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, D; vll path;
//***********//
int main() {
	cin >> N;
	vl C(N);
	vll L(200000);
	for (i = 0; i < N; i++) {
		cin >> C[i];
		C[i]--;
		L[C[i]].push_back(i);
	}
	vl dp(N);
	dp[0] = 1;
	vl now(200000);
	for (i = 0; i < N-1; i++) {
		(dp[i + 1] += dp[i])%=MOD;
		if (now[C[i]] < L[C[i]].size() - 1) {
			if (L[C[i]][now[C[i]]] + 1 < L[C[i]][now[C[i]] + 1]) {
				(dp[L[C[i]][now[C[i]] + 1]] += dp[i]) %= MOD;
			}
			now[C[i]]++;
		}
	}
	
	cout << dp[N - 1];
}