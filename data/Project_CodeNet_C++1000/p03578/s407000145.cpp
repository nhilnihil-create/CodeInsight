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
	
	map<int, int> mp;
	for(int i = 0; i < n; ++i) {
		int d;
		cin >> d;
		mp[d]++;
	}
	
	int m;
	cin >> m;
	
	vector<int> t(m);
	for(int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	
	bool yes = true;
	for(int i = 0; i < m; ++i) {
		if( mp[t[i]] == 0 ) {
			yes = false;
			break;
		}
		
		mp[t[i]]--;
	}
	
	if( yes ) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
