#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<queue>
#define int long long
using namespace std;
signed main() {
	int n, m, ans = 0; string s; cin >> n >> s;
	for (int h = 0; h < n; h++) {
		if (s[h] == 'R') {
			ans++;
		}
		else {
			ans--;
		}
	}
	if (ans > 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}