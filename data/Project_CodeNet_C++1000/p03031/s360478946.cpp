//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>

// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
using qul = queue<ll>;
using pql = priority_queue<ll>;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#pragma region header
//#define int long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define INF (ll)10000000000000000
#define mod (ll)1000000007
#define P pair<lint,lint>
#pragma endregion
#pragma endregion


int main(void) {
	lint n, m; cin >> n >> m;
	vl k(m);
	vector<vector<lint>> s(m);
	set<pair<lint, lint>> t;
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		s[i].resize(k[i]);
		for (int j = 0; j < k[i]; j++) {
			cin >> s[i][j];
			t.insert({ i,s[i][j] - 1 });
		}
	}
	vector<bool> r(n);
	lint ans = 0;
	vector<short> p(m);
	for (int i = 0; i < m; i++) cin >> p[i];
	for (int a = 0; a < (1 << n); a++) {
		for (int i = 0; i < n; i++) {
			if ((a >> i) & 1) r[i] = true;
			else r[i] = false;
		}
		for (int i = 0; i < m; i++) {
			lint cnt = 0;
			for (int j = 0; j < n; j++) {
				if (r[j]) {
					if (t.count({ i,j })) cnt++;
				}
			}
			if (cnt % 2 != p[i]) goto kaage;
		}
		ans++;
	kaage:;
	}
	printf("%lld\n", ans);

	return 0;
}