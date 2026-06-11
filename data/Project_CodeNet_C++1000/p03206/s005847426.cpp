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
	int d;
	cin >> d;
	
	if( d == 25 ) cout << "Christmas" << endl;
	else if( d == 24 ) cout << "Christmas Eve" << endl;
	else if( d == 23 ) cout << "Christmas Eve Eve" << endl;
	else if( d == 22 ) cout << "Christmas Eve Eve Eve" << endl;
	
	return 0;
}
