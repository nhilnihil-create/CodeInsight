#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main() {
	int n, m, lm = 0, rm = 1000000000;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		lm = max(lm, l);
		rm = min(rm, r);
	}
	int ans = 0;
	bool a = 0;
	for(int i = 0;i<=n; ++i) {
		if(lm <= i && i <= rm)
			++ans;
	}
	cout << ans << endl;
}