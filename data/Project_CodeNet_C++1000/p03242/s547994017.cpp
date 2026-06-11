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
	
	for(int i = 0; i < s.size(); ++i) {
		if( s[i] - '0' == 1 ) cout << 9;
		if( s[i] - '0' == 9 ) cout << 1;
	}
	
	cout << endl;
	
	return 0;
}
