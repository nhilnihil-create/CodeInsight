#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)



int main() {
	ll n;
	cin >> n;
	ll a[n];
	rep(i, n) {
		cin >> a[i];
	}
	if (a[0] != 0) {
		cout << -1 << endl;
		return 0;		
	}

	rep(i, n - 1) {
		if (a[i] + 1 < a[i + 1]) {
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = a[n - 1];

	for(int i = n - 2; i >= 0; i--) {
		if (a[i] + 1 == a[i + 1]) {
			continue;			
		}
		ans += a[i];
	}

	cout << ans << endl;

	return 0;
}
