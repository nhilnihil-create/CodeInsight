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
			string t = s.substr(0, i) + s.substr(j);
			
			if( t == "keyence" ) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}
