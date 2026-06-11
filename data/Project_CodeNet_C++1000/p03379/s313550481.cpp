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
	
	vector<ll> x(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	vector<ll> y = x;
	
	sort(y.begin(), y.end());
	
	for(int i = 0; i < n; ++i) {
		if( x[i] <= y[n / 2 - 1] ) cout << y[n / 2] << endl;
		else cout << y[n / 2 - 1] << endl;
	}
	
	return 0;
}
