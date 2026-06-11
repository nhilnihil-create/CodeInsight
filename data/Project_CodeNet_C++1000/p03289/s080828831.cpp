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
	ll n, m, a = 0, b = 0, cnt = 0, ans = 0; string s; cin >> s;
	for (int h = 0; h < s.size(); h++) {
		if (h == 0) { if ((ll)s[h] == 65) { cnt++; } }
		else if ((ll)s[h] == 67) { 
			if (a == 0 && 2 <= h && h <= s.size() - 2) { cnt++; a++; }
		}
		else {
			if (97 <= (ll)(s[h]) && (ll)s[h] <= 122) { cnt++; }
		}
	}
	if (a == 1 && cnt == s.size()) { cout << "AC" << endl; }
	else { cout << "WA" << endl; }
	cin >> n; return 0;
}