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
	string s;
	cin >> n >> s;
	
	int ans = 0;
	for(int i = 1; i < n - 1; ++i) {
		string tmp = s.substr(0, i);
		string tmp2 = s.substr(i, n - i);
		
		map<char, int> mp1, mp2;
		for(int i = 0; i < tmp.size(); ++i) {
			mp1[tmp[i]]++;
		}
		
		for(int i = 0; i < tmp2.size(); ++i) {
			mp2[tmp2[i]]++;
		}
		
		int cnt = 0;
		for(char c = 'a'; c <= 'z'; ++c) {
			if( mp1[c] > 0 && mp2[c] > 0 ) cnt++;
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
	
	return 0;
}
