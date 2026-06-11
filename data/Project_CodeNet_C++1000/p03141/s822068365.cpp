#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// 全国統一プログラミング王決定戦予選-C, 1138, 17:18(UNSOLVED), 解説AC
	int n; cin >> n;
	vector<T> v(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		v[i] = T(a + b, a, b);
	}
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	rep(i, n) {
		if (i % 2 == 0) ans += ll(get<1>(v[i]));
		else ans -= ll(get<2>(v[i]));
	}
	cout << ans << endl;

	return 0;
}