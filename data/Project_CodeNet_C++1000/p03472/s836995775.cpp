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
	ll n, h;
	cin >> n >> h;

	vector<ll> a(n);
	vector<ll> b(n);
	ll x = 0;

	rep(i, n) {
		cin >> a[i] >> b[i];
		if (a[i] > x) x = a[i];
	}

	sort(b.begin(), b.end(), greater<>());
	ll cnt = 0, i = 0;
	bool flag = true;;

	while (h > 0) {
		if (x < b[i] && flag) {
			h -= b[i];
			cnt++;
			i++;
			if (i == n) {
				flag = false;
				i = 0;
			}
		}
		else {
			cnt += (h - 1) / x + 1;
			break;
		}
	}
	
	cout << cnt;

	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}