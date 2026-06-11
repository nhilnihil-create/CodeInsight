#include <bits/stdc++.h>
#define N 15
using namespace std;
int n,m,k[N],s[N][N],p[N],cnt,mod[N];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=m;i++){
			int sum=0;
			for(int j=1;j<=k[i];j++)
				sum+=p[s[i][j]];
			if(sum%2!=mod[i])return;
		}
		cnt++;return;
	}
	p[x]=1,dfs(x+1);
	p[x]=0,dfs(x+1);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>s[i][j];
	}
	for(int i=1;i<=m;i++)cin>>mod[i],mod[i]%=2;
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}