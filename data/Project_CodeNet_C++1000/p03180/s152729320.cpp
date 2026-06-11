#include <bits/stdc++.h>
using namespace std;
const int N = 17;
int n, a[N][N];
long long f[1<<N],dp[1<<N];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<1<<n;i++){
		for(int j=0;j<n;j++){
			if(i>>j&1){
				f[i]=f[i^(1<<j)];
				for(int k=0;k<n;k++) if(i>>k&1) f[i]+=a[j][k];
			}
		}
	}
	for(int i=1;i<1<<n;i++){
		for(int j=i;j;j=(j-1)&i){
			dp[i]=max(dp[i],dp[i^j]+f[j]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}