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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string s;
	cin >> s;
	
	int cnt1 = ((int)s.size() - 1) * 9;
	
	if( (int)(s.front() - '0') > 1 ) {
		cnt1 += (int)(s.front() - '0') - 1;
	}
	
	int cnt2 = 0;
	ll tmp = stoll(s);
	
	while( tmp ) {
		cnt2 += (tmp % 10);
		tmp /= 10;
	}
	
	cout << max(cnt1, cnt2) << endl;
	
	return 0;
}
