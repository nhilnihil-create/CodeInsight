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
	
	vector<int> sum(n + 1, 0);
	for(int i = 0; i < n; ++i) { 
		sum[i + 1] = sum[i] + (s[i] == 'W');
	}
	
	int ans = n;
	for(int i = 0; i <= n; ++i) {
		ans = min(ans, sum[i - 1] + (n - i) - (sum[n] - sum[i]));
	}
	
	cout << ans << endl;
	
	return 0;
}
