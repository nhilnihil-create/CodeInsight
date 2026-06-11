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
	int a, b, c;
	cin >> a >> b >> c;
	
	int ma = max({a, b, c});
	int mi = min({a, b, c});
	int mid = a + b + c - ma - mi;
	cout << ma * 10 + mid + mi << endl;
	
	return 0;
}
