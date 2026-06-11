#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
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

// ===============================================================
//using系

using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ld = long double;
using qul = queue<ll>;
using pql = priority_queue<ll>;

// ========================================================================
//define系

//#define int long long;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i <= n; i++)

// ========================================================================


ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}
//最大公約数
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
//最小公倍数
ll box(double a)
{
	ll b = a;
	return b;
}
//切り捨て
ll fff(double a)
{
	ll b = a + 0.5;
	return b;
}
//四捨五入
ll mch(ll n) {
	if (n == 1) return 1;
	else return n * mch(n - 1);
}
//1から整数nまでの階乗を出す(INFで割っていない)
bool prime(ll a)//素数判定、primeならtrue,違うならfalse
{
	if (a < 2) return false;
	else if (a == 2) return true;
	else if (a % 2 == 0) return false;
	double m = sqrt(a);
	for (int i = 3; i <= m; i += 2)
	{
		if (a % i == 0)
		{
			return false;
		}
	}

	// 素数である
	return true;
}
//素数判定
ll modpow(ll a, ll n, ll mod) {
	ll hi = 1;
	while (n > 0) {
		if (n & 1) hi = hi * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return hi;
}
//いろいろやります（ただの前座）
ll mg(ll a, ll mod) {
	return modpow(a, mod - 2, mod);
}
//割り算の10^9+7等対策で逆元を出します 




// ========================================================================


/*signed*/int main() {
	ll n, k; cin >> n >> k;
	vl a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vl b(n + 1, 0);
	for (int i = 0; i < n; i++) {
		b[a[i]]++;
	}
	sort(b.begin(), b.end());
	ll cnt = 0;
	for (int i = 0; i < n + 1; i++) {
		if (b[i] > 0) cnt++;
	}
	if (cnt <= k) cout << 0 << endl;
	else {
		k = cnt - k;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] != 0) {
				if (k == 0) break;
				else {
					k--;
					cnt += b[i];
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}