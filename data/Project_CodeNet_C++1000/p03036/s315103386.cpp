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
	ll r, d, x;
	cin >> r >> d >> x;
	
	for(int i = 0; i < 10; ++i) {
		x = r * x - d;
		cout << x << endl;
	}
	
	return 0;
}
