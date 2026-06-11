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

int nC2(int n) {
	return n * (n - 1) / 2;
}
int main(void) {
	int k;
	cin >> k;
	cout << nC2(k) - nC2(k / 2) - nC2(k - k / 2) << endl;
	
	return 0;
}
