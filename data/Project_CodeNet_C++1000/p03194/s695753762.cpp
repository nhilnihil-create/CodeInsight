#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
	ll n, p;
	cin >> n >> p;
	ll ans = 0;

	//除外
	if (p == 1) {
		cout << 1;
		return 0;
	}
	if (n == 1) {
		cout << p;
		return 0;
	}

	//1から最大公約数を検索
	for (ll i = 1; pow(i, n) <= p; i++) {
		ll D = pow(i, n);
		//指数表示にして指数がnと同じなら
		if (p%D == 0)ans = max(ans, i);
	}
	cout << ans;
}