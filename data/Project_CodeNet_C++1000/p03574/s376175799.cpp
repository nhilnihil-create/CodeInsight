#include<bits/stdc++.h>
using namespace std;
int ans[51][51] = {0};
int n, m;
void fboom(int ans[51][51], int i, int j) {
	if (i>0) for (int k=j-1; k<=j+1; k++) {
		if (ans[i-1][k]!=-1) ans[i-1][k]++;
	}
	if (i<n-1) for (int k=j-1; k<=j+1; k++) {
		if (ans[i+1][k]!=-1) ans[i+1][k]++;
	}
	if (j>0) if (ans[i][j-1]!=-1) ans[i][j-1]++;
	if (j<m-1) if (ans[i][j+1]!=-1) ans[i][j+1]++;
}
int main () {
	cin >> n >> m;
	char map[51][51];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			char c; cin>>c;
			if (c=='#') {
				ans[i][j]=-1;
				fboom(ans, i, j);
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (ans[i][j]==-1) cout << "#";
			else cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}