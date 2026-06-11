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
	
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	vector<ll> b(n), p;
	ll sum = 0LL;
	int num = 0;
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		
		if( b[i] > a[i] ) {
			sum -= (a[i] - b[i]);
			num++;
		} else {
			p.push_back(a[i] - b[i]);
		}
	}
	
	if( num == 0 ) {
		cout << 0 << endl;
		return 0;
	}
	
	int ans = num;
	sort(p.begin(), p.end(), greater<ll>());
	
	ll x = 0LL;
	for(int i = 0; i < (int)p.size(); ++i) {
		x += p[i];
		ans++;
		
		if( x >= sum ) break;
	}
	
	if( x >= sum ) cout << ans << endl;
	else cout << -1 << endl;
	
	return 0;
}
