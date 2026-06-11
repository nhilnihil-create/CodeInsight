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

template<typename T>
map<T, T> prime_factor(T n) {
	map<T, T> res;
	
	for(T i = 2; i * i <= n; ++i) {
		while( n % i == 0 ) {
			res[i]++;
			n /= i;
		}
	}
	
	if( n != 1 ) res[n] = 1;
	
	return res;
}

int main(void) {
	ll n, p;
	cin >> n >> p;
	
	auto prf = prime_factor(p);
	
	ll ans = 1LL;
	for(auto x : prf) {
		if( x.second >= n ) {
			ans *= (ll)pow(x.first, x.second / n);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
