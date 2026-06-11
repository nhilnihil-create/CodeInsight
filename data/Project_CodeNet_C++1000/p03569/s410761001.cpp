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
	string s;
	cin >> s;


	ll n = s.size(), i = 0, j = n - 1, x = 0;
	bool flag = false;

	while (i <= j) {
		if (s[i] != s[j]) {
			if (s[i] == 'x') {
				x++;
				i++;
			}
			else if (s[j] == 'x') {
				x++;
				j--;
			}
			else {
				flag = true;
				break;
			}
		}
		else {
			i++;
			j--;
		}
	}

	if (flag) cout << -1;
	else cout << x;

	return 0;
}



ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}