#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;


int main(void) {
	int n, m, i, a[100003] = {};
	map<int, int> am;

	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (i = 1; i <= n; i++) {
		a[i] = (a[i - 1] + a[i]) % m;
	}

	for (i = 0; i <= n; i++) {
		am[a[i]]++;
	}

	ll ans = 0;
	map<int, int>::iterator ite;

	for (ite = am.begin(); ite != am.end(); ite++) {
		ans += (ll)(ite->second) * (ite->second - 1) / 2;
	}

	cout << ans << endl;

	return 0;
}