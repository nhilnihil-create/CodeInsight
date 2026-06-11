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
	int n, h, w;
	cin >> n >> h >> w;
	
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		
		if( a >= h && b >= w ) ans += min(a / h, b / w);
	}
	
	cout << ans << endl;
	
	return 0;
}
