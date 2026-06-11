#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=510005;

int n,m;
int a[N],dp[N][2],mx[N];

void chang(int p,int w){
	if (w>=dp[p][1]){
		swap(dp[p][1],dp[p][0]);
		dp[p][1]=w;
		return;
	}
	if (w>dp[p][0]) dp[p][0]=w;
}

int main(){
	int i,j;
	scanf("%d",&n); m=(1<<n)-1;
	for (i=0;i<=m;i++) scanf("%d",&a[i]);
	for (i=1;i<=m;i++) mx[i]=a[i]+a[0];
	for (i=1;i<=m;i++){
		chang(i,a[0]);
		for (j=i;j;j=((j-1)&i)) chang(i,a[j]);
		mx[i]=dp[i][1]+dp[i][0];
	}
	for (i=1;i<=m;i++) mx[i]=max(mx[i],mx[i-1]);
	for (i=1;i<=m;i++) printf("%d\n",mx[i]);
	return 0;
}