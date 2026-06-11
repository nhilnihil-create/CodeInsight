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
	int n, h;
	cin >> n >> h;
	
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	sort(b.begin(), b.end(), greater<int>());
	
	int x = *max_element(a.begin(), a.end());
	int ans = 0;
	
	for(int i = 0; i < n; ++i) {
		if( h > 0 && x < b[i] ) {
			h -= b[i];
			ans++;
		}
	}
	
	if( h > 0 ) { 
		if( h % x == 0 ) ans += h / x;
		else ans += h / x + 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
