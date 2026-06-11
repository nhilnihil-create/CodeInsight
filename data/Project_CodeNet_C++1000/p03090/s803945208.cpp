#include<bits/stdc++.h>
using namespace std;
int n,ans[110][110];
int main(){
	int cnt = 0;
	scanf("%d",&n);
	if(n%2==1){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if((i+j)!=n)ans[i][j]=1,cnt++;
	}
	else {
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if((i+j)!=(n+1))ans[i][j]=1,cnt++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(ans[i][j]==1)printf("%d %d\n",i,j);
	return 0;
} 