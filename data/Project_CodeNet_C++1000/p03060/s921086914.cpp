#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	//入力
	int n;
	cin >> n;
	vector<int> v(n), c(n);
	rep(i, n) cin >> v[i];
	rep(i, n) cin >> c[i];
	int ans = 0;
	rep(i, n) {
		if ((double)v[i] / c[i] > 1.0) {
			ans += v[i] - c[i];
		}
	}
	std::cout << ans << endl;
}