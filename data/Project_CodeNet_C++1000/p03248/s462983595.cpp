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
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	string s;
	cin >> s;
	int n = s.size();
	if (s[0] == '0' || s[n - 2] == '0' || s[n - 1] == '1') {
		cout << -1 << endl;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[n - 2 - i]) {
			cout << -1 << endl;
			return 0;
		}
		if (s[i] == '1') cnt++;
	}
	for (int i = 1; i <= cnt; i++) {
		cout << i << ' ' << i + 1 << endl;
	}
	int pl = 1;
	int num = cnt + 2;
	for (int i = 0; i < n - 2; i++) {
		while (s[i] == '0') {
			cout << pl << ' ' << num << endl;
			num++; i++;
		}
		pl++;
	}
}