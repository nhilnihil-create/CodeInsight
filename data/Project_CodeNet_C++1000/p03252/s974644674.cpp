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
    string S, T;

    cin >> S >> T;

	int N = S.size();
	map<char, char> mp1, mp2;
	rep(i, N) {
		if (mp1.count(S[i])) {
			if (mp1[S[i]] != T[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
		mp1[S[i]] = T[i];
		if (mp2.count(T[i])) {
			if (mp2[T[i]] != S[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
		mp2[T[i]] = S[i];
	}

	cout << "Yes" << endl;

    return 0;
}


ll gcd(ll a, ll b) {
    if (a % b == 0)return(b);
    else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}