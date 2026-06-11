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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int h, w;
	cin >> h >> w;
	
	vector< vector<int> > c(10, vector<int>(10, 0));
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			cin >> c[i][j];
		}
	}
	
	for(int k = 0; k < 10; ++k) {
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 10; ++j) {
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}
	
	int a; 
	ll ans = 0;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			cin >> a;
			
			if( a == -1 ) continue;
			
			ans += c[a][1];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
