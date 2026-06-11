#include <bits/stdc++.h>
using namespace std;
const int MAXN=17;
long long a[MAXN][MAXN],score[1<<MAXN],dp[1<<MAXN];
int n;

int main(){
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	for(int S=0;S<(1<<n);++S)
		for(int i=0;i<n;++i)
			for(int j=0;j<i;++j)
				if(S>>i&1 && S>>j&1) score[S]+=a[i][j];
	for(int S=1;S<(1<<n);++S)
		for(int k=S;k;k=(k-1)&S)
			dp[S]=max(dp[S],score[k]+dp[S^k]);
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}