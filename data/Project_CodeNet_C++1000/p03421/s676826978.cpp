#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#define int long long
#define INF 1000000009
#define LINF 1000000000000000009
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

signed main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a + b > n + 1 || a * b < n) {
		cout << -1 << endl;
		return 0;
	}
	if (b == 1) {
		for (int i = 1; i <= n; i++) cout << i << ' ';
		cout << endl;
		return 0;
	}
	vector<int> ans;
	for (int i = n + 1 - a; i <= n; i++) ans.push_back(i);
	int base = (n - a) / (b - 1);
	int over = n - a - base * (b - 1);
	int c = ans[0] - base;
	if (over != 0) c--;
	for (int i = 0; i < over; i++) {
		for (int j = 0; j <= base; j++) {
			ans.push_back(c);
			c++;
		}
		c -= 2 * base + 2;
	}
	if (over != 0) c++;
	for (int i = over; i < b - 1; i++) {
		for (int j = 0; j < base; j++) {
			ans.push_back(c);
			c++;
		}
		c -= 2 * base;
	}
	//cout << base << ' ' << over << endl;
	for (int i : ans) cout << i << ' ';
	cout << endl;
}