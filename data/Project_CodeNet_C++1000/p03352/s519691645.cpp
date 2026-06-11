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
	ll x;
	cin >> x;
	
	vector<bool> ok(x + 1, false);
	ok[1] = true;
	
	for(int i = 2; i <= x; ++i) {
		int a = i * i;
		while( a <= x ) {
			ok[a] = true;
			a *= i;
		}
	}
	
	for(int i = x; i >= 1; i--) {
		if( ok[i] ) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}
