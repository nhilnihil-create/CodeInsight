#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char s[H+2][W+2];
	rep(i,H+2)rep(j,W+2) s[i][j] = '.';
	for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
		cin >> s[i][j];
	}

	for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
		if (s[i][j] == '#') {
			if (s[i-1][j] == '#' || s[i+1][j] == '#') continue;
			if (s[i][j-1] == '#' || s[i][j+1] == '#') continue;
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;	

	return 0;
}
