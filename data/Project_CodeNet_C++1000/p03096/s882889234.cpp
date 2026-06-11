#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=1e9+7;
int n,a[N],dp[N],s[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	int m=1;
	for (int i=2;i<=n;i++)
		if (a[i]!=a[i-1])a[++m]=a[i];
	dp[0]=1;
	for (int i=1;i<=m;i++){
		dp[i]=(s[a[i]]+dp[i-1])%M;
		(s[a[i]]+=dp[i-1])%=M;
	}
	printf("%d\n",dp[m]);
}
