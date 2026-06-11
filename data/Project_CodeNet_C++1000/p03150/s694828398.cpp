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
	
	int n = (int)s.size();
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n + 1; ++j) {
			string tmp;
			
			for(int k = 0; k < n; ++k) {
				if( i <= k && k < j ) continue;
				
				tmp.push_back(s[k]);
			}
			
			if( tmp == "keyence" ) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}
