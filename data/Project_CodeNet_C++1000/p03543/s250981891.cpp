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
	string s;
	cin >> s;
	
	if( (s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3]) ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}
