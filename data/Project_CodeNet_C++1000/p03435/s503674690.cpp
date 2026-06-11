#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int c[3][3];
	rep(i,3) rep(j,3) cin >> c[i][j];
	int sa[3][4];
	//
	rep(i,3) {
		sa[i][0] = c[i][0] - c[i][1];
		sa[i][1] = c[i][1] - c[i][2];
		sa[i][2] = c[0][i] - c[1][i];
		sa[i][3] = c[1][i] - c[1][i];
	}

	if (sa[0][0] == sa[1][0] && sa[1][0] == sa[2][0]) {
		if (sa[0][1] == sa[1][1] && sa[1][1] == sa[2][1]) {
			if (sa[0][2] == sa[1][2] && sa[1][2] == sa[2][2]) {
				if (sa[0][3] == sa[1][3] && sa[1][3] == sa[2][3]) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}