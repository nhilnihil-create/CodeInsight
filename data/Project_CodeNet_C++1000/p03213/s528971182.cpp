#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
bool prime[1001];
int cnt[1001];
int dp[333][333];

void solve()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=1000;++i)if(prime[i]){
		for(int j=i*2;j<=1000;j+=i) prime[j]=false;
	}
	for(int i=2;i<=N;++i)if(prime[i]){
		int x = N;
		while(x >= i){
			cnt[i] += x / i;
			x /= i;
		}
	}
	dp[0][1]=1;
	for(int i=1;i<=N;++i)for(int j=0;j<=75;++j){
		for(int k=1;k<=cnt[i]+1;++k)if(j*k<=75){
			dp[i][j*k]+=dp[i-1][j];
		}
	}
	cout << dp[N][75] << '\n';
}

int main()
{
	cin >> N;
	solve();
	return 0;
}