#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <iomanip>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <memory.h>
#include <cassert>
#include <complex>
#include <ctime>
#include <limits>

using namespace std;

using ll = long long;
using ld = long double;
using db = double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>; 

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vld = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;
using vvl = vector<vl>;

using si = set<int>;
using sl = set<ll>;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rs resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define nl "\n"
#define trav(i, x) for (auto& i: x)

const int MOD = 998244353;
const int MX = 5005;
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

ll lcm(ll a, ll b) { return (a / (__gcd(a, b)) * b); }
ll gcd(ll a, ll b) { return (__gcd(a, b)); }
ll pow(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
	str res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; for(int i = 0; i < SZ; i++) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	bool fst = 1; str res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
	return "("+ts(p.f)+", "+ts(p.s)+")"; }

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vi v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vi a;
	for(int i = 0; i < n; i++) {
		a.pb(abs(v[i] - x));
	}
	int mul;
	for(int i = 0; i < sz(a); i++) {
		if(i == 0) {
			mul = a[i];
		} else {
			mul = gcd(mul, a[i]);
		}
	}
	cout << mul << nl;
}
