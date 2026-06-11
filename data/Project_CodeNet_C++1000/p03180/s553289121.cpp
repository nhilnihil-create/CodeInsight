#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#include <bits/stdc++.h>
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

int arr[16][16], dp[(1<<16)];

	

main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i < (1<<n); i++) {
		for (int x = 0; x < n; x++) {
			if ((1<<x) & i) {
				for (int y = x + 1; y < n; y++) {
					if ((1<<y) & i) {
						dp[i] += arr[x][y];
					} 
				}
			}
		}
		int tmp = i;
		while (tmp) {
			dp[i] = max(dp[i], dp[tmp] + dp[tmp ^ i]);
			tmp = (tmp - 1) & i;
		}
	}
	cout << dp[(1<<n)-1] << "\n";
}
