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
//dijkstra, WarshallFloyd, BellmanFord, UnionFind, COM, digitDP ,RMQ//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D; vll path;
//***********//
int main() {
	cin >> N;
	vll R(N);
	for (i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		R[i] = { a, b, 0 };
	}
	vpll B(N);
	for (i = 0; i < N; i++) {
		ll c, d;
		cin >> c >> d;
		B[i] = make_pair(c, d);
	}
	sort(B.begin(), B.end());
	for (i = 0; i < N; i++) {
		ll match = -1;
		ll y = -1;
		for (j = 0; j < N; j++) {
			if (R[j][0] < B[i].first && R[j][2] == 0 && R[j][1] > y && R[j][1]<B[i].second) {
				y = R[j][1];
				match = j;
			}
		}
		if (match >= 0) {
			R[match][2] = 1;
			ans++;
		}
	}
	cout << ans;
}