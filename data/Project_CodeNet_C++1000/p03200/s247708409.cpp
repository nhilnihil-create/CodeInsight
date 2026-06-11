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
	string s;
	cin >> s;
	
	int n = (int)s.size();
	ll ans = 0, cnt = 0;
	for(int i = 0; i < n; ++i) {
		if( s[i] == 'B' ) cnt++;
		else ans += cnt;
	}
	
	cout << ans << endl;

	return 0;
}
