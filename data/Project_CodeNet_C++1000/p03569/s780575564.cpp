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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string s;
	cin >> s;
	
	int n = (int)s.size();
	int left = 0, right = n - 1;
	int ans = 0;
	
	while( left < right ) {
		if( s[left] == s[right] ) {
			left++;
			right--;
		} else if( s[left] == 'x' ) {
			left++;
			ans++;
		} else if( s[right] == 'x' ) {
			right--;
			ans++;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
