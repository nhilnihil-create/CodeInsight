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
	int a, b;
	cin >> a >> b;
	
	if( a % 2 == 0 || b % 2 == 0 ) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}
