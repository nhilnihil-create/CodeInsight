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
	
	vector<int> t(n), x(n), y(n);
	for(int i = 0; i < n; ++i) {
		cin >> t[i] >> x[i] >> y[i];
	}
	
	int nowx = 0, nowy = 0, prevt = 0;
	bool yes = true;
	for(int i = 0; i < n; ++i) {
		int dL = abs(nowx - x[i]) + abs(nowy - y[i]);
		int dT = t[i] - prevt;
		
		if( (dL % 2 != dT % 2) || (dL > dT) ) {
			yes = false;
			break;
		}
		
		nowx = x[i]; 
		nowy = y[i];
		prevt = t[i];
	}
	
	if( yes ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
