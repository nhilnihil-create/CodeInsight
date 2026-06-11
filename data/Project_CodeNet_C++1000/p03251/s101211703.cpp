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
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	
	vector<int> x(n), y(m);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	for(int i = 0; i < m; ++i) {
		cin >> y[i];
	}
	
	int maxX = *max_element(x.begin(), x.end());
	int minY = *min_element(y.begin(), y.end());
	bool yes = false;
	
	if( maxX < minY ) {
		for(int i = maxX + 1; i <= minY; ++i) {
			if( i > X && i <= Y ) {
				yes = true;
				break;
			}
		}
	}
	
	if( yes ) cout << "No War" << endl;
	else cout << "War" << endl;
	
	return 0;
}
