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
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	ll n, p;
	cin >> n >> p;
	
	map<ll, ll> prf;
	
	for(ll i = 2; i * i <= p; ++i) {
		while( p % i == 0 ) {
			prf[i]++;
			p /= i;
		}
	}
	
	if( p != 1 ) prf[p] = 1;
	
	ll ans = 1LL;
	for(auto x : prf) {
		if( x.second >= n ) {
			ans *= (ll)pow(x.first, x.second / n);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
