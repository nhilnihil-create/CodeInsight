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

const int maxn = 4e5+5;
const int mod = 1e9 + 7;

int dp[1005][1005];
char c[1005][1005];

main() {
	IOS
	int n, m;
	cin >> n >> m;
//	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == '#') dp[i][j] = 0;
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= mod;
			if (i == 1 && j == 1) dp[1][1] = 1;
		}
	} 
	cout << dp[n][m] << "\n";
}
