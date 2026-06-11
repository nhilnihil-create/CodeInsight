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

ll mpow(ll n, ll p) {
	ll res = 1LL;
	while( p ) {
		if( p & 1 ) res *= n;
		
		n *= n;
		p >>= 1;
	}
	
	return res;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	
	ll ans = mpow(2LL, m) * (1900 * m + (n - m) * 100);
	cout << ans << endl;
	
	return 0;
}
