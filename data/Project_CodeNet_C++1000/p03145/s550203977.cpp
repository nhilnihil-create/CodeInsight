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
	
	int x = min({a, b, c});
	int y = a + b + c - x - max({a, b, c});
	cout << x * y / 2 << endl;
	
	return 0;
}
