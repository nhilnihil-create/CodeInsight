#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	ll k, a, b;
	cin >> k >> a >> b;
	
	if( b - a <= 2 ) {
		cout << k + 1LL << endl;
	} else {
		if( k <= a - 1 ) {
			cout << k + 1LL << endl;
			return 0;
		}
		
		ll ans = a;
		k -= (a - 1LL);
		ans += k % 2 + (b - a) * max(0LL, k / 2LL);
		cout << ans << endl;
	}
	
	return 0;
}
