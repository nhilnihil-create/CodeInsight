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
vl flag, color, D, Ans, inter; vll path;
int main() {
	long double ans = 0;
	cin >> N;
	vector<long double> T(N+1), V(N+2);
	long double sum = 0;
	T[0] = 0;
	for (i = 1; i <= N; i++) {
		long double t;
		cin >> t;
		T[i] = T[i - 1] + t;
		sum += t;
	}
	V[0] = 0; V[N + 1] = 0;
	for (i = 1; i <= N; i++) {
		cin >> V[i];
	}
	for (long double i = 0; i < sum; i+=0) {
		long double y1 = INF;
		for (long double j = 1; j <= N; j++) {
			if (i < T[j-1]) {
				y1 = min(y1, V[j] + (T[j-1] - i));
			}
			else if (T[j] < i) {
				y1 = min(y1, V[j] + (i - T[j])); 
			}
			else {
				y1 = min(y1, V[j]);
			}
			y1 = min(y1, min(i,sum-i));
		}
		i += 0.5;
		long double y2 = INF;
		for (long double j = 1; j <= N; j++) {
			if (i < T[j - 1]) {
				y2 = min(y2, V[j] + (T[j - 1] - i));
			}
			else if (T[j] < i) {
				y2 = min(y2, V[j] + (i - T[j]));
			}
			else {
				y2 = min(y2, V[j]);
			}
		}
		y2 = min(y2, min(i, sum - i));
		//debug(i - 0.5, y1, y2);
		ans += (y1 + y2) / 4;
	}
	cout << fixed << setprecision(12) << ans;
}