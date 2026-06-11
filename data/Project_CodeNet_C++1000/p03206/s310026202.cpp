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
	int n;
	cin >> n;
	
	string ans = "Christmas";
	if( n != 25 ) {
		for(int i = 0; i < 25 - n; ++i) {
			ans += " Eve";
		}	
	}
	
	cout << ans << endl;
	
	return 0;
}
