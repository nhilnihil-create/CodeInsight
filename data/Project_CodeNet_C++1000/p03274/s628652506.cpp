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
	int n, k;
	cin >> n >> k;
	
	vector<ll> x(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	int ans = 1e9;
	for(int i = 0; i < n - k + 1; ++i) {
		int l = x[i];
		int r = x[i + k - 1];
		int tmp;
		
		if( r < 0 ) { 
			tmp = -l;
		} 
		else if( l >= 0 ) {
			tmp = r;
		} 
		else {
			tmp = min(2 * (-l) + r, -l + 2 * r);
		}
		
		ans = min(ans, tmp);
	}

	cout << ans << endl;
	
	return 0;
}
