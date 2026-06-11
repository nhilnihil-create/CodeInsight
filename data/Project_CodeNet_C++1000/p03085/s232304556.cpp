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
	char c;
	cin >> c;
	
	if( c == 'A' ) cout << 'T' << endl;
	if( c == 'T' ) cout << 'A' << endl;
	if( c == 'G' ) cout << 'C' << endl;
	if( c == 'C' ) cout << 'G' << endl;
	
	return 0;
}
