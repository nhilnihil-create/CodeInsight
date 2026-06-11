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
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	
	ll ans = 0;
	for(int ri = 0; ri <= n; ++ri) {
		for(int gi = 0; gi <= n; ++gi) {
			int bi = n - ri * r - gi * g;
			
			if( bi >= 0 && bi % b == 0 ) ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
