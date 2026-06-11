#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <array>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V>void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HOME
#warning CHECK int:ll::INT_MAX:LLONG_MAX
#define maxn 20
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define gcd __gcd
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define ss second
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define PI 3.14159265358979323846264338327950L
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};


int main() {

	int n, m; cin >> n >> m;
	vector<vector<int>> bulb(m);
	for (int i = 0; i <= m - 1; i++) {
		int k; cin >> k;
		bulb[i].resize(k, 0);
		for (int j = 0; j <= k - 1; j++) cin >> bulb[i][j], bulb[i][j]--;
	}

	vector<int> p(m); for (int i = 0; i <= m - 1; i++) cin >> p[i];

	auto check = [&](int msk) -> bool {
		for (int j = 0; j <= m - 1; j++) {
			int cnt = 0;
			for (auto s : bulb[j]) {
				if ((msk & (1 << s)) != 0) cnt++;
			}
			if (cnt % 2 != p[j]) return false;
		}
		return true;
	};

	int ans = 0;
	for (int mask = 0; mask <= (1 << n) - 1; mask++) {
		if (check(mask)) ans++;
	}

	cout << ans;

	return 0;
}