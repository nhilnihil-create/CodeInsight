#include <bits/stdc++.h>
using namespace std;

const int N=505;
int A[N][N], D[31][31];
int dp[3][31];
int main() {
	int n,c;
	cin >> n >> c;
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			cin >> D[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> A[i][j];
			A[i][j]--;
		}
	}

	for (int i=0; i<c; i++) {
		for (int x=0; x<n; x++) {
			for (int y=0; y<n; y++) {
				int t=(x+y)%3;
				dp[t][i]+=D[A[x][y]][i];
			}
		}
	}
	int ans=1e9;
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			if ( i==j ) continue;
			for (int k=0; k<c; k++) {
				if ( i==k || j==k ) continue;
				int res=dp[0][i]+dp[1][j]+dp[2][k];
				ans=min(res,ans);
			}
		}
	}
	cout << ans << '\n';
    return 0;
}