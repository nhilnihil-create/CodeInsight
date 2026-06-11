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
	string s;
	cin >> n >> s;
	
	vector<int> b(n + 1, 0), w(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		b[i + 1] = b[i];
		w[i + 1] = w[i];
		
		if( s[i] == '#' ) b[i + 1]++;
		else w[i + 1]++;
	}
	
	int ans = 1e9;
	for(int i = 0; i < n + 1; ++i) {
		ans = min(ans, b[i] + w[n] - w[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
