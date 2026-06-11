// スタックサイズ: 100MB

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define fst first
#define snd second
ll pw(ll x, ll y) { ll r = 1;  rep(i, y) { r *= x; }; return r; }


int main() {
	
	ll A, B;
	cin >> A >> B;
	--A, --B;

	enum {wh, bl};
	ll ans[100][100];
	rep(i, 100) rep(j, 100) {
		if (i < 50) ans[i][j] = wh;
		else ans[i][j] = bl;
	}

	for (ll i = 1; i < 50; i += 2) {
		for (ll j = 1; j < 100; j += 2) {
			if (B == 0) goto po;
			ans[i][j] = bl;
			--B;
		}
	}
po:

	for (ll i = 51; i < 100; i += 2) {
		for (ll j = 1; j < 100; j += 2) {
			if (A == 0) goto po2;
			ans[i][j] = wh;
			--A;
		}
	}
po2:

	cout << "100 100" << endl;
	rep(i, 100) {
		rep(j, 100) {
			if (ans[i][j] == bl) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
}