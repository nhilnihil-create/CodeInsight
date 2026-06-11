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

const int maxn = 4e2+5;
int arr[maxn], pre[maxn];

int dp[maxn][maxn];

int dfs(int l,int r) {
	if (l == r) return dp[l][r] = 0;
	else if (dp[l][r] != -1) return dp[l][r];
	else {
		dp[l][r] = 1e18;
		for (int i = l; i < r; i++) {
			dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i + 1, r) + pre[r] - pre[l - 1]); 
		}
		return dp[l][r];
	} 
}

main() {
	IOS
	int n;
	cin >> n;
	pre[0] = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> arr[i], pre[i] = pre[i - 1] + arr[i];
	cout << dfs(1, n);
}
