#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = (1LL << 31) - 1;
const ll mod = 1e9 + 7;

ll n, m, q;

ll D[501][501];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n>>m>>q;
	FOR(i, 0, m) {
		ll l, r; cin >> l >> r;
		D[l][r]++;
	}
	FOR(i, 1, n+1)FOR(j,1, n+1) {
		D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
	}

	FOR(i, 0, q) {
		ll  l, r; cin >> l >> r;
		cout << D[r][r] - D[l - 1][r] - D[r][l - 1] + D[l - 1][l - 1] << endl;
	}


}