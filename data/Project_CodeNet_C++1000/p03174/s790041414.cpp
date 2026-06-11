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

const int maxn = 21;
const int mod = 1e9 + 7;
bool arr[maxn][maxn];
int dp[1<<21][maxn + 5] = {};

main() {
	IOS
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1<<n); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) cnt++;
		}
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j))) {
				if (arr[j][cnt]) {
					dp[i | (1<<j)][cnt+1] += dp[i][cnt];
					dp[i | (1<<j)][cnt+1] %= mod;
				}
			}
		}
	}
	cout << dp[(1<<n)-1][n] << "\n";
}