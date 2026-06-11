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
	int r;
	cin >> r;
	
	if( r < 1200 ) cout << "ABC" << endl;
	else if( r < 2800 ) cout << "ARC" << endl;
	else cout << "AGC" << endl;
	
	return 0;
}
