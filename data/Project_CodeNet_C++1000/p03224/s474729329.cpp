#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[12345678];
signed main() {
	int n, cnt = 1, sum = 1, ans = 1; cin >> n;
	vector<vector<int>>aa(1000);
	for (int h = 1; h < 1000; h++) {
		test[h * (h + 1) / 2] = h;
	}
	if (test[n] == 0) { cout << "No" << endl; return 0; }
	cout << "Yes" << endl;
	cout << test[n] + 1 << endl;
	for (int h = 0; h <= test[n]; h++) {
		cout << test[n]; cnt = sum;
		for (int i = 0; i < aa[h].size(); i++) {
			cout << ' ' << aa[h][i];
		}
		for (int i = 0; i < test[n] - aa[h].size(); i++) {
			cout << ' ' << ans; aa[cnt].push_back(ans); cnt++; ans++;
		}
		cout << endl; sum++;
	}
	return 0;
}