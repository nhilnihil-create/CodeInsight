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
	int n, m;
	cin >> n >> m;
	
	vector<ll> a(n);
	ll sum = 0LL;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	
	vector< pair<ll, int> > p;
	for(int i = 0; i < m; ++i) {
		int b;
		ll c;
		cin >> b >> c;
		p.push_back( {c, b} );
	}
	
	sort(a.begin(), a.end());
	sort(p.begin(), p.end());
	
	ll ans = 0LL;
	for(int i = 0; i < n; ++i) {
		if( p.back().first <= a[i] || p.empty() ) {
			ans += a[i];
		} else {
			ans += p.back().first;
			p.back().second--;
			
			if( p.back().second == 0 ) p.pop_back();
		}
	}

	cout << ans << endl;
	
	return 0;
}
