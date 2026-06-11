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
signed main() {
	ll n, ans = 0; cin >> n;
	for (int h = 1; h <= 3500; h++) {
		for (int i = 1; i <= 3500; i++) {
			ll atai = 4 * h * i - n * i - n * h;
			if (atai > 0 && (n * h * i) % atai == 0) {
				cout << h << ' ' << i << ' ' << n * h * i / atai << endl;
				cin >> n; return 0;
			}
		}
	}
	cin >> n; return 0;
}