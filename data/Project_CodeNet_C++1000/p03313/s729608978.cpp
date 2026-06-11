#include<bits/stdc++.h>
using namespace std;
#define N 18
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<'\n';
#define trace(a) cout<<#a<<": "<<a<<"\n"
int a[(1<<N)];
multiset<int> fr[(1<<N)];
multiset<int> dp[(1<<N)][N+1];
int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,k,l,m,n,t;
	cin >> n;
	for(i = 0;i < (1<<n);i++) {
		cin >> a[i];
		// dp[i][-1]
		fr[i].insert(-a[i]);
	}
	for(i = 0;i < (1<<n);i++) {
		for(j = 0;j <= n;j++) {
			if((i>>j)&1) {
				if(j == 0) {
					dp[i][j].insert(fr[i].begin(),fr[i].end());
					dp[i][j].insert(fr[i^(1<<j)].begin(),fr[i^(1<<j)].end());
					while(dp[i][j].size() > 2) {
						dp[i][j].erase(--dp[i][j].end());
					}
				}
				else {
					// dp[i][j] = dp[i][j-1] + dp[i^(1<<j)][j-1];
					dp[i][j].insert(dp[i][j-1].begin(),dp[i][j-1].end());
					dp[i][j].insert(dp[i^(1<<j)][j-1].begin(),dp[i^(1<<j)][j-1].end());
					while(dp[i][j].size() > 2) {
						dp[i][j].erase(--dp[i][j].end());
					}
				}
			}
			else {
				if(j == 0) {
					dp[i][j] = fr[i];
					// dp[i][j].insert(fr[i].begin(),fr[i].end());
					// while(dp[i][j].size() > 2) {
					// 	dp[i][j].erase(--dp[i][j].end());
					// }
				}
				else {
					dp[i][j] = dp[i][j-1];
					// dp[i][j].insert(dp[i][j-1].begin(),dp[i][j-1].end());
					// while(dp[i][j].size() > 2) {
					// 	dp[i][j].erase(--dp[i][j].end());
					// }
				}
			}
		}
	}
	int an = 0;
	for(i = 1;i < (1<<n);i++) {
		int can =  -(*dp[i][n].begin() + *dp[i][n].rbegin());
		an = max(an,can);
		cout << an << endl;
	}
}