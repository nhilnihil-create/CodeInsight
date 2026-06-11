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
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> s(M);
	vector<ll> p(M);
	rep(i, M){
	ll k;
		cin >> k;
		rep(j, k) {
			ll S;
			cin >> S;
			S--;
			s[i].push_back(S);
		}
	}
	rep(i, M) {
		cin >> p[i];
	}

	ll ans = 0;
	for (ll mask = 0; mask < 1 << N; mask++) {
		ll flag = 0;
		rep(i, M) {
			ll cnt = 0;
			rep(j, s[i].size()){
				ll sw = s[i][j];
				if (mask >> sw & 1) cnt++;
			}
			if (cnt % 2 == p[i]) continue;
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) ans++;
	}

	cout << ans << endl;

    return 0;
}
