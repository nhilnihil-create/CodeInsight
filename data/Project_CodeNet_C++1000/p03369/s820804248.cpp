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
	
	int ans = 700;
	for(int i = 0; i < (int)s.size(); ++i) {
		if( s[i] == 'o' ) ans += 100;
	}
	
	cout << ans << endl;
	
	return 0;
}
