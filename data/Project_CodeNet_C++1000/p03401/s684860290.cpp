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
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	a.emplace(a.begin(), 0);
	a.push_back(0);
	
	int cost = 0;
	
	for(int i = 1; i < a.size(); ++i) {
		cost += abs(a[i] - a[i - 1]);
	}
	
	for(int i = 1; i <= n; ++i) {
		int ans = cost + abs(a[i - 1] - a[i + 1]) - (abs(a[i] - a[i + 1]) + abs(a[i] - a[i - 1]));
		cout << ans << endl;
	}
	
	return 0;
}
