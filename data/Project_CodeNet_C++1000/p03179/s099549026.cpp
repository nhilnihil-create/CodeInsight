#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int bd[3001][3001], n;
char c;
int main() {
	cin >> n;
	memset(bd, 0, sizeof(bd));
	bd[0][0] = 1;
	for (int i=1; i<n; i++) {
		cin >> c;
		if (c=='<') {
			bd[i][0] = 0;
			for (int j=1; j<=i; j++) {
				bd[i][j] = (bd[i][j-1] + bd[i-1][j-1])%M;
			}
		}
		if (c=='>') {
			bd[i][i] = 0;
			for (int j=i-1; j>=0; j--) 
				bd[i][j] = (bd[i][j+1] + bd[i-1][j])%M;
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		ans += bd[n-1][i];
		ans %= M;
	}
	cout << ans << "\n";
}