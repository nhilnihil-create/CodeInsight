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
	ll n;
	cin >> n;
	
	for(ll h = 1; h <= 3500; ++h) {
		for(ll t = 1; t <= 3500; ++t) {
			ll x = n * h * t;
			ll y = 4 * h * t - n * t - n * h;
			
			if( y != 0 && x % y == 0 && x / y > 0 ) {
				cout << h << " " << t << " " << x / y << endl;
				return 0;
			}
		}			
	}
	
	return 0;
}
