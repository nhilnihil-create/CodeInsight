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
	int k;
	cin >> s >> k;
	
	int n = s.size();
	vector<string> str;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j <= k; ++j) {
			string tmp = s.substr(i, j);
			str.push_back(tmp);
		}
	}
	
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	
	cout << str[k - 1] << endl;
	
	return 0;
}
