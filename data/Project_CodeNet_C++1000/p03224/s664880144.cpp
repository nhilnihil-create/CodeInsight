#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define case(i) cout<<"Case #"<<i<<": "
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pr;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;


int main() {
	int n; cin >> n;
	int k = 0;
	while (k * (k + 1) / 2 != n) {
		k++;
		if (k > 1000) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << k+1 << endl;
	vector<vector<int>> ans(k+1);
	int cnt = 0;
	rep(i, 0, k)rep(j, i+1, k+1) {
		cnt++;
		ans[i].push_back(cnt);
		ans[j].push_back(cnt);
	}
	rep(i, 0, k+1) {
		cout << ans[i].size();
		for (int j: ans[i]) {
			cout << " " << j;
		}
		cout << endl;
	}
	return 0;
}
