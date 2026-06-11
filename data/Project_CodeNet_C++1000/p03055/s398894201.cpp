#include<bits/stdc++.h>
using namespace std;
vector<int>e[400010];
int zj=0;
int dfs(int x,int pre){
	int m1=0,m2=0;
	for(auto i:e[x])if(i!=pre){
		int gg=dfs(i,x);
		if(gg>m1)m2=m1,m1=gg;
		else if(gg>m2)m2=gg;
	}
	zj=max(zj,m1+m2+1);
	return m1+1;
}
bool ans[400010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,1);
	ans[1]=1;ans[2]=0;
	for(int i=3;i<=zj;i++)ans[i]=!(ans[i-1]&ans[i-2]);
	puts(ans[zj]==1?"First":"Second");
	return 0;
}
