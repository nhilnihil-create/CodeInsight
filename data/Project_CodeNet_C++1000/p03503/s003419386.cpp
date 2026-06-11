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
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
//**デバッグ準備**//
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
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
//rep, vin, all, iteLoop//
//gcdlcm, isPrime, eratos, Npow, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = -INF; ll z = 0, o = 1;
vl flag, color, D; vector<vector<tuple<ll, ll, ll>>> path;
//***********//
vl bitList(ll n, ll k, ll f) {
	vl bitList(k);
	for (ll i = 0; i < k; i++) {
		bitList[i] = f % n;
		f /= n;
	}
	return bitList;
}
int main() {
	cin >> N;
	vll F(N, vl(10, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < 10; j++) {
			cin >> F[i][j];
		}
	}
	vll P(N, vl(11, 0));
	for (i = 0; i < N; i++) {
		for (j = 0; j < 11; j++) {
			cin >> P[i][j];
		}
	}
	for (i = 1; i < pow(2,10); i++) {
		ll pre = 0;
		vl Q = bitList(2, 10, i);
		for (j = 0; j < N; j++) {
			ll count = 0;
			for (k = 0; k < 10; k++) {
				if (Q[k] && F[j][k]) count++;
			}
			pre += P[j][count];
		}
		ans = max(ans, pre);
	}
	cout << ans;
}
