#include <bits/stdc++.h>
#define re register
#define LL long long
#define SIZE 20
using namespace std;
int n;
LL a[SIZE][SIZE];
LL sum[1<<SIZE],dp[1<<SIZE];
int main()
{
	cin>>n;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			cin>>a[i][j];
	for(re int S=0;S<(1<<n);S++)
		for(re int i=1;i<=n;++i)
			if((S&(1<<(i-1)))!=0)
				for(re int j=1;j<=n;++j)
					if((S&(1<<(j-1)))!=0)				
						dp[S]+=a[i][j];
	for(re int S=0;S<(1<<n);++S)
		for(re int K=S;K;K=(K-1)&S)
			dp[S]=max(dp[S],dp[K]+dp[S^K]);
	cout<<dp[(1<<n)-1]/2<<endl;
	return 0;
} 