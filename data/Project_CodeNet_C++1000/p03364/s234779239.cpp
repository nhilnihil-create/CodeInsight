
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin >> n;
	char board[3*n][3*n];
	f(i,0,n) f(j,0,n) cin>>board[i][j];
	f(i,0,3*n) f(j,0,3*n)
		board[i][j] = board[i%n][j%n];
	int dp[3*n][3*n];
	f(i,0,3*n) f(j,0,3*n) {
		int k = 0;
		while (i+k<3*n && j+k<3*n && board[i+k][j] == board[i][j+k])
			k++;
		dp[i][j] = k;
	}
	int cnt = 0;
	f(i,0,n) f(j,0,n) {
		int ni = i+n, nj = j+n;	
		bool found = 1;
		f(k,0,n) if (dp[ni+k][nj+k]<n-k) {
			found = 0;
			break;
		}
		cnt += found; 
	}
	cout << cnt << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

