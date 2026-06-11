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

const int maxn = 3e3+5;

double arr[maxn];
double dp[maxn][maxn];

main() {
	IOS 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1][1] = arr[1];
	dp[1][0] = (double)1 - arr[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j] += dp[i - 1][j] * (1.00 - arr[i]);
			dp[i][j+1] += dp[i - 1][j] * (arr[i]);
		}
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i > n - i) ans += dp[n][i];
	}
	printf("%.9f", ans);
		



}
