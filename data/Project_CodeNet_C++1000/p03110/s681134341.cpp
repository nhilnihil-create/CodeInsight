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
	
	double ans = 0.0;
	for(int i = 0; i < n; ++i) {
		double x;
		string s;
		cin >> x >> s;
		
		if( s == "JPY" ) ans += x;
		else ans += x * 380000.0;
	}
	
	printf("%.10f\n", ans);
	
	return 0;
}
