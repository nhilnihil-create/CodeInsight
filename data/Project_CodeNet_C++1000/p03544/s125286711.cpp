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
	ll n;
	cin >> n;
	
	vector<ll> L(n + 1);
	L[0] = 2LL; L[1] = 1LL;
	for(int i = 2; i <= n; ++i) {
		L[i] = L[i - 1] + L[i - 2];
	}
	
	cout << L[n] << endl;
	
	return 0;
}
