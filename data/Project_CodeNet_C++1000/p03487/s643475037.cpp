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
	
	map<int, int> mp;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		mp[a]++;
	}
	
	int ans = 0;
	for(auto& x : mp) {
		int tmp = x.second - x.first;
		
		if( tmp > 0 ) { 
			ans += tmp;
		} else if( tmp < 0 ){
			ans += x.second;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
