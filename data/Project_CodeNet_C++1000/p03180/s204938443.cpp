#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 19;
int N;
int a[MAX_N][MAX_N];
ll dp[1<<MAX_N];

void solve()
{
	for(int i=0;i<(1<<N);++i)for(int x=0;x<N;++x)if(i>>x&1){
		for(int y=x+1;y<N;++y)if(i>>y&1){
			dp[i]+=a[x][y];
		}
	}
	for(int i=0;i<(1<<N);++i){
		for(int j=i;j>0;j=(j-1)&i) {
			dp[i]=max(dp[i],dp[j]+dp[i^j]);
		}
	}
	cout << dp[(1<<N)-1] << '\n'; 
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j) cin>>a[i][j];
	solve();
	return 0;
}