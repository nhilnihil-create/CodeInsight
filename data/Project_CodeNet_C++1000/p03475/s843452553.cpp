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
	
	n--;
	vector<int> c(n), s(n), f(n);
	for(int i = 0; i < n; ++i) {
		cin >> c[i] >> s[i] >> f[i];
	}
	
	for(int i = 0; i < n; ++i) {
		int t = c[i] + s[i];
		
		for(int j = i + 1; j < n; ++j) {
			if( t < s[j] ) { 
				t += s[j] - t;	
			} else if( t > s[j] && t % f[j] != 0 ) { 
				t += (f[j] - t % f[j]);
			}
			
			t += c[j];
		}
		
		cout << t << endl;
	}
	
	cout << 0 << endl;
	
	return 0;
}
