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
 
const int maxn = 3e3 + 5;
const int mod = 1e9 + 7;
int dp[maxn][maxn];
char s[maxn];
 
main() {
//	string s;
	int n;
	cin >> n >> (char*)(s + 2); 
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] == '>') {
			dp[i][i] = 0;
			for (int j = i - 1; j >= 1; j--) {
				dp[i][j] = dp[i-1][j] + dp[i][j+1];
				dp[i][j] %= mod;
			}
		}else {
			dp[i][1] = 0;
			for (int j = 2; j <= i; j++) {
				dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
				dp[i][j] %= mod;
			}
		} 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[n][i];
		ans %= mod; 
	}
	cout << ans << "\n";
 
}