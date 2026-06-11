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
	
	int ans = 0;
	int BA = 0, frontB = 0, endA = 0;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		int m = s.size();
		for(int j = 0; j < m - 1; ++j) {
			if( s[j] == 'A' && s[j + 1] == 'B' ) ans++;
		}	
		
		if( s[0] == 'B' && s[m - 1] == 'A' ) BA++;
		else if( s[0] == 'B' && s[m - 1] != 'A' ) frontB++;
		else if( s[0] != 'B' && s[m - 1] == 'A' ) endA++;		
	}
	
	if( frontB == 0 && endA == 0 ) {
		ans += max(0, BA - 1);
	} else {
		ans += min(frontB + BA, endA + BA);
	}
	
	cout << ans << endl;
	
	return 0;
}
