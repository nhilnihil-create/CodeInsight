#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=405;
#define infl 		9223372036854775807
//each node represents a range
struct node{
	int v=infl; //sum of values in range
	int cj=infl; //minimum cost of joining them
};

node dp[N][N];

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//input
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1; i<=n; ++i){
		cin>>a[i];
		dp[i][i].v=a[i];
		dp[i][i].cj=0;
	}
	//presum
	int ps[n+1]={};
	for(int i=1; i<=n; ++i){
		ps[i] = a[i] + ps[i-1];
	}

	for(int gap=1; gap<=n-1; ++gap)
	{
		for(int i=1; i+gap<=n; ++i){
			int l=i, r=i+gap;
			
			dp[l][r].v = ps[r]-ps[l-1];
			
			for(int lend=l; lend<r; ++lend){
				if(dp[l][lend].cj + dp[lend+1][r].cj +dp[l][r].v<= dp[l][r].cj)
				{
					dp[l][r].cj = dp[l][lend].cj + dp[lend+1][r].cj +dp[l][r].v;
				}
			}

		}
	}

	cout<<dp[1][n].cj<<endl;

	return 0;	
}