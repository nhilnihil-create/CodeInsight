#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	char s[H+2][W+2];
	rep(i,H+2)rep(j,W+2) s[i][j] = '.';
	for (int i = 1; i <= H; i++) {	
		string st;
		cin >> st;
		for (int j = 1; j <= W; j++) {
			s[i][j] = st[j-1];
		}
	}
	
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (s[i][j] == '.') {
				int sum = 0;
				for (int k = -1; k < 2; k++) {
				for (int l = -1; l < 2; l++) {
					sum += s[i+k][j+l] == '#';
				}
				}
				cout << sum;
			}	
			else cout << '#';
		}	
		cout << endl;
	}
	return 0;
}
