#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <queue>
#include <memory>
#include <fstream>
#include <strstream>


#pragma GCC optimize("no-stack-protector,Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,abm,mmx,tune=native,avx,avx2")

#define int long long
#define ld long double
#define eb emplace_back
#define pb pop_back
#define mp make_pair
#define ss second
#define ff first
#define sqr(x) (x) * (x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef int(*func)(int a, int b);

using namespace std;

const int INF = 1e9 + 7;
const int B = 299;
const int MOD = 1e9 + 123;
const ld EPS = 1e-7;
const ld PI = 3.14159265358979323;
const int MAXN = 2100;

random_device rd;
mt19937 get_rand(rd());

int gcd(int a, int b) {
	return (!a ? b : gcd(b % a, a));
}

vector < vector < int > > g;
bool u[2010], c[2010];

bool dfs(int v, bool z) {
	u[v] = 1;
	c[v] = z;
	for (auto i : g[v]) {
		bool k = 1;
		if (!u[i])
			k = dfs(i, !z);
		if (c[i] == z || !k)
			return 0;
	}
	return 1;
}


signed main() {
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
#ifdef _LOCAL
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(0);
	srand(time(NULL));

	int t = 1;
	//cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int n = b - a - 1;
		cout << n * (n + 1) / 2 - a << endl;
	}
	return 0;
}