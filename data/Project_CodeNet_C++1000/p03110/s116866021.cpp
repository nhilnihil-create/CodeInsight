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
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
signed main() {
	double n, m, a = 0, b = 0, cnt = 0, ans = 0; cin >> n;
	string s, t;
	for (int h = 0; h < n; h++) {
		cin >> a >> s;
		if (s == "JPY") { ans += a; }
		else {
			ans += a * 380000;
		}
	}
	printf("%.10f\n", ans);
	cin >> n; return 0;
}