#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++ )

int main() {
	string a;
	cin >> a;

	int ans = 0;
	rep(i, 0, 4) {
		if (a.at(i) == '2') {
			ans++;
		}
	}
	cout << ans << endl;
	}