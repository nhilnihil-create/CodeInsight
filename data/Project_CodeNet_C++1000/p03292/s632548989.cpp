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
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	
	vector<int> a = {a1, a2, a3};
	sort(a.begin(), a.end());
	
	cout << a[1] - a[0] + a[2] - a[1] << endl;
	
	return 0;
}
