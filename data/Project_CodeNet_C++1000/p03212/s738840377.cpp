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

ll dfs(ll x, bool a, bool b, bool c, ll n) {
	if( x > n ) return 0;
	
	ll res = 0;
	
	if( x <= n && x != 0 && a && b && c ) res++;
	
	res += dfs(10 * x + 3, true, b, c, n);
	res += dfs(10 * x + 5, a, true, c, n);
	res += dfs(10 * x + 7, a, b, true, n);
	
	return res;
}

int main(void) {
	ll n;
	cin >> n;
	
	ll ans = dfs(0LL, false, false, false, n);
	
	cout << ans << endl;
	
	return 0;
}
