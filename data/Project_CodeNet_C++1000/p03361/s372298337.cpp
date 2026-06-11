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
	int h, w;
	cin >> h >> w;
	
	vector<string> s(h);
	for(int i = 0; i < h; ++i) {
		cin >> s[i];
	}
	
	vector<int> dx = {0, 1, -1, 0}, dy = {1, 0, 0, -1};
	
	bool yes = true;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			bool ok = false;
			
			if( s[i][j] == '.' ) continue;
			
			else {
				for(int k = 0; k < 4; ++k) {
					if( i + dx[k] < 0 || i + dx[k] >= h || j + dy[k] < 0 || j + dy[k] >= w ) continue;
					
					if( s[i + dx[k]][j + dy[k]] == '#' ) {
						ok = true;
						break;
					}
				}
			}
			
			if( !ok ) {
				yes = false;
				break;
			}
		}
	}
	
	if( yes ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
