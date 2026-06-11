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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if( abs( a - c ) <= d  || ( abs(a - b) <= d && abs(b - c) <= d ) ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
