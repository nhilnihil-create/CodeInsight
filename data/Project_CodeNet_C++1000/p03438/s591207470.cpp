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
	
	vector<ll> a(n), b(n);
	ll add_a = 0LL, add_b = 0LL;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		add_a += a[i];
	}
	
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		add_b += b[i];
	}
	
	ll limit = add_b - add_a;
	
	ll one = 0LL, two = 0LL;
	for(int i = 0; i < n; ++i) {
		if( a[i] < b[i] ) {
			two += (b[i] - a[i] + 1LL) / 2LL;
		} else if( a[i] > b[i] ) {
			one += a[i] - b[i];
		}
	}
	
	if( limit >= one && limit >= two ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
