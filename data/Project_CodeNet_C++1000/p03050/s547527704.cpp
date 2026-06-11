#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// diverta 2019 Programming Contest-D, 1095, 
	ll ans = 0;
	ll n; cin >> n;
	ll sq = sqrt(n);
	for (ll i = 1; i <= sq; ++i) {
		if ((n - i) % i == 0) ans += (n - i) / i > i ? (n - i) / i : 0;
	}
	cout << ans << endl;
	return 0;
}