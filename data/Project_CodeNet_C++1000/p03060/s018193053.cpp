#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;

int main() {

	ll n;
	
	cin >> n;

	vector<int> c(n);
	vector<int> v(n);
	vector<int> r(n);

	rep(i, n) {
		cin >> v[i];
	}
	rep(i, n) {
		cin >> c[i];
	}
	rep(i, n) {
		r[i] = v[i] - c[i];
	}
	int ans = 0;

	rep(i, n) {

		if (r[i] > 0)ans += r[i];

	}

	cout << ans << endl;
	return 0;
}