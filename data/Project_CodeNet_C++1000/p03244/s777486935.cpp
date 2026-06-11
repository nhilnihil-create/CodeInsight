#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

int main() {

	int n;
	cin >> n;
	vector<ll> o(100005, 0), e(100005, 0);
	ll v;

	for (ll i = 0; i < n; i++) {
		cin >> v;
		if (i % 2 == 1)o[v]++;
		else e[v]++;
	}

	ll i = max_element(e.begin(), e.end()) - e.begin();
	ll j = max_element(o.begin(), o.end()) - o.begin();
	if (i != j) cout << n - e[i] - o[j] << endl;
	else {
		sort(e.begin(), e.end(), greater<ll>());
		sort(o.begin(), o.end(), greater<ll>());
		ll an = min(n - e[0] - o[1], n - e[1] - o[0]);

		cout << an << endl;
	}
    return 0;
}