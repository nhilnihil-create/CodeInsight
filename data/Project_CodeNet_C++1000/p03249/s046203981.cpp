#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
#include <random>
#include <cmath>
#include <complex>
// #include "utiltime.hpp"

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef complex<double> cdouble;

const int INFL = (int)1e9;
const ll INFLL = (ll)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loopll(i, n) for(ll i = 0; i < (ll)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopll1(i, n) for(ll i = 1; i <= (ll)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = (ll)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define Looprll1(i, n) for(ll i = (ll)n; i >= 1; i--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define printv(vector) Loop(i, vector.size()) { cout << vector[i] << " "; } cout << endl;
#define printmx(matrix) Loop(i, matrix.size()) { Loop(j, matrix[i].size()) { cout << matrix[i][j] << " "; } cout << endl; }
#define quickio() ios::sync_with_stdio(false); cin.tie(0);
#define readfile(filename) ifstream in(filename); cin.rdbuf(in.rdbuf());
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
bool nearlyeq(double x, double y) { return abs(x - y) < 1e6; }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(double x) { ll m = (ll)sqrt(x); return m + (m * m <= (ll)(x) ? 0 : -1); }
ll ceilsqrt(double x) { ll m = (ll)sqrt(x); return m + ((ll)x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }

/*******************************************************/

void failed() {
	cout << -1 << endl;
	exit(0);
}

int main() {
	int n; cin >> n;
	vector<Pll> a(n);
	Loop(i, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vll subtree_cnt(n, 0);
	vll d(n, 0);
	vector<Pll> ans;
	Loopr1(i, n - 1) {
		ll target_val = a[i].first + subtree_cnt[i] * 2 - (ll)n + 2;
		auto itr = lower_bound(a.begin(), a.end(), Pll({ target_val, 0LL }));
		if (itr == a.end()) failed();
		if (itr - a.begin() == (a.size() - 1)) failed();
		if (itr->first != target_val) failed();
		subtree_cnt[itr - a.begin()] += subtree_cnt[i] + 1;
		ans.push_back({ a[i].second + 1, a[itr - a.begin()].second + 1 });
		d[itr - a.begin()] += subtree_cnt[i] + d[i] + 1;
		a.pop_back();
		subtree_cnt.pop_back();
	}
	if (d[0] != a[0].first) failed();
	Loop(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}