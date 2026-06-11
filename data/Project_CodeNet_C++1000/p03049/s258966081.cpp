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
	
	vector<string> s(n);
	int ans = 0;
	int AB = 0, BA = 0;
	int frontB = 0, endA = 0;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		
		int m = s[i].size();
		for(int j = 0; j < m - 1; ++j) {
			if( s[i][j] == 'A' && s[i][j + 1] == 'B' ) ans++;
		}	
		
		if( s[i][0] == 'B' && s[i][m - 1] == 'A' ) BA++;
		else if( s[i][0] == 'B' && s[i][m - 1] != 'A' ) frontB++;
		else if( s[i][0] != 'B' && s[i][m - 1] == 'A' ) endA++;		
	}
	
	if( BA == 0 ) {
		ans += min(frontB, endA);
	} else {
		if( frontB + endA > 0 ) {
			ans += (BA + min(frontB, endA));
		} else if( frontB + endA == 0 ) {
			ans += BA - 1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
