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
	
	string check = "MARCH";
	vector<ll> cnt(5, 0LL);
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		for(int j = 0; j < (int)check.size(); ++j) {
			if( s[0] == check[j] ) { 
				cnt[j]++;
			}
		}
	}
	
	ll ans = 0LL;
	for(int i = 0; i < 5; ++i) {
		for(int j = i + 1; j < 5; ++j) {
			for(int k = j + 1; k < 5; ++k) {
				ans += cnt[i] * cnt[j] * cnt[k];
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
