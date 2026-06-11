
#define _USE_NATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <random>
#include <tuple>


using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
#define EPS 1e-9
const int INF = 1050000000;
const long long LINF = 1LL << 60;
const ll MOD = 1e9 + 7;
const int MINF = -1050000000;

ll LCM(ll a, ll b) {
	if (b == 0) return a;
	else {
		a = a % b;
		return LCM(b,a);
	}
}

ll GCD(ll a, ll b) {
	return a * b / LCM(a, b);
}


int main() {
	ll n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	ll L = LCM(n, m);
	ll res = n / L * m;
	n /= L, m /= L;
	bool exist = true;
	for (ll i = 0; i < L; ++i) {
		if (s[i*n] != t[i*m]) exist = false;
	}
	if(exist) cout << res << endl;
	else cout << -1 << endl;
	return 0;
}
