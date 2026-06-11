#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void) {
	int n, m, i,c=0;
	cin >> n >> m;
	vector<int> x(m),v(m-1);
	rep(i, m) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	rep(i, m - 1) {
		v[i] = x[i + 1] - x[i];
	}
	sort(v.begin(),v.end());

	rep(i, x.size() - n) {
		c += v[i];
	}
	cout << c << endl;
	return 0;
}






















