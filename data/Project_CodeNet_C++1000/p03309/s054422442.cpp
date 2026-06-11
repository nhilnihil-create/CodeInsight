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
	
	vector<int> diff(n);
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		diff[i] = a - (i + 1);
	}
	
	sort(diff.begin(), diff.end());
	
	int b = diff[n / 2];
	ll ans = 0LL;
	
	for(int i = 0; i < n; ++i) {
		ans += abs(diff[i] - b);
	}
	
	cout << ans << endl;
	
	return 0;
}
