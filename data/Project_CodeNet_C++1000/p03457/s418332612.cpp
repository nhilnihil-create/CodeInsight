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
	int n;
	cin >> n;
	
	int nowx = 0, nowy = 0, prevt = 0;
	bool yes = true;
	for(int i = 0; i < n; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		
		int dL = abs(nowx - x) + abs(nowy - y);
		int dT = t - prevt;
		
		if( (dL % 2 != dT % 2) || (dL > dT) ) {
			yes = false;
		}
		
		nowx = x; nowy = y; prevt = t;
	}
	
	if( yes ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
