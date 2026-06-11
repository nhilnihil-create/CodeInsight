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
	string S;
	cin >> S;

	ll ans = S.size();
	rep(i, S.size() - 1) {
		if (S[i] != S[i + 1]) ans = min(ans, max(i + 1, (ll)S.size() - 1 - i));
	}
	cout << ans << endl;
}