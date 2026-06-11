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
	int n, m;
	cin >> n >> m;
	
	int ans = (int)pow(2.0, (double)m) * (1900 * m + 100 * (n - m));
	cout << ans << endl;
	
	return 0;
}
