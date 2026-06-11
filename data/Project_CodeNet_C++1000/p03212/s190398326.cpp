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

void dfs(ll now, int &ans, int digit, const ll n) {
	if( now > n ) return;
	
	if( digit >= 1 && now <= n ) {
		bool a = false;
		bool b = false;
		bool c = false;
		string t = to_string(now);
		
		for(int i = 0; i < (int)t.size(); ++i) {
			if( t[i] == '3' ) a = true;
			if( t[i] == '5' ) b = true;
			if( t[i] == '7' ) c = true;
		}
		
		if( a && b && c ) ans++;
	}
	
	vector<ll> dd = {3, 5, 7};
	for(auto& x : dd) {
		ll v = now;
		v *= 10;
		v += x;
		dfs(v, ans, digit + 1, n);
	}
}

int main(void) {
	ll n;
	cin >> n;
	
	int ans = 0;
	dfs(0, ans, 0, n);
	
	cout << ans << endl;
	
	return 0;
}
