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
#include <numeric>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define co(i) cout << i << endl;
#define co2(i,j) cout << i << " " << j << endl;
#define co3(i) cout << i << " ";
#define po(i) cout << i.first << " " << i.second << endl;
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
//rep, vin, all, iteLoop, bitSearch, bitList, nod, digitDP, treeDP//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv, doubling//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal, RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007, INF = 1LL << 60, ans = 0, z = 0, o = 1;
vl flag, D; vll path;
//***********//
int main() {
	cin >> M >> K;
	if (M == 0) {
		if (K == 0) cout << "0 0";
		else cout << -1;
	}
	else if (M == 1) {
		if (K == 0) cout << "0 0 1 1";
		else cout << -1;
	}
	else {
		if (K >= pow(2, M)) cout << -1;
		else {
			vl P;
			for (i = 0; i < pow(2, M); i++) {
				if (i != K) P.push_back(i);
			}
			vl Q = P;
			reverse(Q.begin(), Q.end());
			for (i = 0; i < P.size(); i++) cout << P[i] << " ";
			cout << K << " ";
			for (i = 0; i < Q.size(); i++) cout << Q[i] << " ";
			cout << K;
		}
	}
}