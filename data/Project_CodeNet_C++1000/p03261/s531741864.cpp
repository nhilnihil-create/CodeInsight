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
	
	vector<string> s(n);
	map<string, int> mp; 
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		mp[s[i]]++;
	}
	
	for(auto& x : mp) {
		if( x.second > 1 ) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < n - 1; ++i) {
		if( s[i].back() != s[i + 1].front() ) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	
	return 0;
}
