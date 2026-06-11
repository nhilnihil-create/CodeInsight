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
	int n, x;
	cin >> n >> x;
	
	vector<int> m(n);
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> m[i];
		sum += m[i];
	}
	
	x -= sum;
	int ans = n;
	int minM = *min_element(m.begin(), m.end());
	
	ans += x / minM;
	
	cout << ans << endl;
	
	return 0;
}
