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
	int k;
	cin >> s >> k;
	
	int n = (int)s.size();
	set<string> st;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j <= k; ++j) {
			string sub = s.substr(i, j);
			st.insert(sub);
		}
	}
	
	int cnt = 0;
	for(auto& ss : st) {
		cnt++;
		
		if( cnt == k ) {
			cout << ss << endl;
			return 0;
		}
	}
	
	return 0;
}
