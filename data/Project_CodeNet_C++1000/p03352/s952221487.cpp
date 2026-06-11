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
	int x;
	cin >> x;
	
	vector<bool> ex(x + 1, false);
	ex[1] = true;
	
	for(int i = 2; i <= x; ++i) {
		int m = i * i;
		while( m <= x ) {
			ex[m] = true;
			m *= i;
		}
	}
	
	int ans = 0;
	for(int i = x; i >= 1; i--) {
		if( ex[i] ) {
			ans = i;
			break;
		}
	}
	
	cout << ans << endl;

	return 0;
}
