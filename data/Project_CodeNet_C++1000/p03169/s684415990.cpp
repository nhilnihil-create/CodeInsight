#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define de(x,y) cout<<#x<<" :"<<x<<y;
#define int long long
#define SZ(xx) ((int)xx.size())
#define lowbit(xx) (xx&(-xx))
#define pb push_back
typedef pair<int,int> pii;

const int maxn = 3e2+5;

double dp[maxn][maxn][maxn] = {};
double tmp[maxn * 3][maxn] = {};


main() {
	IOS
	int n;
	cin >> n;
	int sum = 0, cnt[5] = {};
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		sum += x;
		cnt[x]++;
	}
	dp[cnt[3]][cnt[2]][cnt[1]] = 1;
	for (int i = cnt[3]; i >= 0; i--) {
		for (int j = cnt[3] + cnt[2]; j >= 0; j--) {
			for (int k = cnt[1] + cnt[2] + cnt[3]; k >= 0; k--) {
				if (dp[i][j][k]) {
					tmp[i * 3 + j * 2 + k][n - i - j - k] += dp[i][j][k];
					if (i >= 1)
					dp[i-1][j+1][k] = dp[i-1][j+1][k] + dp[i][j][k] * i / (i + j + k);
					if (j >= 1)
					dp[i][j-1][k+1] = dp[i][j-1][k+1] + dp[i][j][k] * j / (i + j + k);
					if (k >= 1)
					dp[i][j][k-1] += (dp[i][j][k] * k) / (i + j + k); 
//					cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n"; 
				}
			}
		}
	} 
	double ans = 0;
	for (int i = sum; i >= 1; i--) {
		double All = 0;
		for (int j = 0; j < n; j++) {
			All += tmp[i][j];
//			cout << tmp[i][j] << " \n"[j==n-1];
		}
		if (!All) continue;
		for (int j = 0; j < n; j++) {
			ans = ans + ((double)tmp[i][j] / All) * (double)n / ((double)n - (double)j);
		}
	
	}
//	cout << ans << "\n";
	printf("%.9f\n", ans);
}
