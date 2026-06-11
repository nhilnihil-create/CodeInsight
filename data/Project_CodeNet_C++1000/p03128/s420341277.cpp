#include<bits/stdc++.h>
using namespace std;

int n,m,a[10],dp[10005];
int c[10]={0,2,5,5,4,5,6,3,7,6};

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> a[i];
	dp[0]=1;
	for(int i = 0; i < m; i++){
		for(int j = c[a[i]]; j <= n;j++)
			dp[j] = max(dp[j],dp[j-c[a[i]]]+1);
	}
	sort(a,a+m);
	m--;
	while(n>0){
		if(n-c[a[m]] >= 0 && dp[n]==dp[n-c[a[m]]]+1){
			n -= c[a[m]];
			cout<<a[m];
		}else m--;
	}
	return 0;
}
