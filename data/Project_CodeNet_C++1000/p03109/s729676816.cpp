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
	string s;
	cin >> s;
	
	if( s[5] == '0' && s[6] - '0' < 5 ) cout << "Heisei" << endl;
	else cout << "TBD" << endl;
	
	return 0;
}
