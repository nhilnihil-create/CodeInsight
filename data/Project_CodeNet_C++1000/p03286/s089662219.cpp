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
	int n;
	cin >> n;
	
	string ans = "";
	
	if( n == 0 ) {
		cout << 0 << endl;
		return 0;
	}
	
	while( n ) {
		if( n % 2 == 0 ) {
			ans += '0';
		} else {
			ans += '1';
			n--;
		}
		
		n /= -2;
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans << endl;
	
	return 0;
}
