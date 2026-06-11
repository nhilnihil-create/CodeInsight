#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int c[3][3];
	rep(i,3)rep(j,3) cin >>c[i][j];
	int d[3][2], e[2][3];
	rep(i,3)rep(j,2) d[i][j] = c[i][j+1] - c[i][j];
	rep(j,3)rep(i,2) e[i][j] = c[i+1][j] - c[i][j];

	rep(i,2) {
		if (d[i][0] == d[i+1][0] && d[i][1] == d[i+1][1]) continue;
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	rep(j,2) {
		if (e[0][j] == e[0][j+1] && e[1][j] == e[1][j+1]) continue;
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}
