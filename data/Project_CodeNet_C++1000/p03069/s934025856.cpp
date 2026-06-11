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
typedef pair<ll, ll> P;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll dx[] = { 1, 0 , -1,  0 }, dy[] = { 0, 1, 0, -1 };

int main() {
	ll n;
	string s;
	cin >> n >> s;
	ll cnt = 0;

	rep(i, n) {
		if (s[i] == '.') cnt++;
	}


	if (cnt == 0 || cnt == n) cout << 0;
	else {
		ll l, r, ans = cnt;
		l = 0;
		r = cnt;
		rep(i, n) {
			if(s[i] == '.'){
				r--;
			}
			else {
				l++;
			}
			ans = min(ans, l + r);
		}
		cout << ans;
	}


	return 0;
}



ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}