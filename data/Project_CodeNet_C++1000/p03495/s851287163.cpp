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
	int n, k;
	cin >> n >> k;
	
	vector<int> cnt(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	
	sort(cnt.begin(), cnt.end());
	
	int ans = 0;
	for(int i = 0; i <= n - k; ++i) {
		ans += cnt[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
