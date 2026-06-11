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
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s;
	a--; b--;
	c--; d--;
	
	for(int i = a; i < c; ++i) {
		if( s[i] == '#' && s[i + 1] == '#' ) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	for(int i = b; i < d; ++i) {
		if( s[i] == '#' && s[i + 1] == '#' ) {
			cout << "No" << endl;
			return 0;
		}
	}
		
	if( c < d ) {
		cout << "Yes" << endl;
	} else if( c > d ) {
		bool threeDot = false;
		
		for(int i = b; i <= d; ++i) {
			if( s.substr(i - 1, 3) == "..." ) {
				threeDot = true;
			}
		}
	
		if( threeDot ) cout << "Yes" << endl;
		else cout << "No" << endl;
	}	
	
	return 0;
}
