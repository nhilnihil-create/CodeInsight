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

template<typename T>
vector<T> Divisors(T n) {
	vector<T> res;
	for(T i = 1; i * i <= n; ++i) {
		if( n % i == 0 ) {
			res.push_back(i);
			
			if( i < n / i ) res.push_back(n / i);
		}
	}
	
	sort(res.begin(), res.end());
	
	return res;
}

int main(void) {
	ll n;
	cin >> n;
	
	vector<ll> div = Divisors(n);
	
	ll ans = 0LL;
	for(auto& x : div) {
		if( x >= (n - x) / x ) break;
		
		ans += (n - x) / x;
	}
	
	cout << ans << endl;
	
	return 0;
}
