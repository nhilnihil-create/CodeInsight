#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {

	int n;
	cin >> n;

	vector<ll> c(n), s(n), f(n);

	rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];

	vector<ll> ans(n);
	ll tmp;

	rep(i, n - 1) {
		tmp = 0;
		repl(j, i, n - 1) {
			if(tmp <= s[j]){
				tmp = c[j] + s[j];
			}
			else {
				ll cnt = (tmp - s[j] - 1) / f[j] + 1;
				tmp = c[j] + s[j] + f[j] * cnt;
			}
		}
		ans[i] = tmp;
	}

	rep(i, n - 1) {
		cout << ans[i] << endl;
	}
	cout << 0;


	return 0;
}


ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}