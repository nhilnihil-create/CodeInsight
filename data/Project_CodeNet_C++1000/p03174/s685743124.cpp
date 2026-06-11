#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
long long n,com[30][30],dp[1<<22],c[1<<22];
vector<int> G[1<<22];
int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> com[i][j];
	for(int i=0; i<(1<<n); i++) for(int j=0; j<n; j++) if(i&(1<<j)) G[i].push_back(j),c[i]++;
	for(int i=0; i<n; i++) dp[1<<i]=com[0][i];
	for(int i=1; i<n; i++)
		for(int j=0; j<(1<<n); j++) if(c[j] == i+1)
			for(auto k:G[j])
				if(com[i][k])
					dp[j]=(dp[j]+dp[j&~(1<<k)])%MOD;
					
	cout << dp[(1<<n)-1];
	return 0;
}