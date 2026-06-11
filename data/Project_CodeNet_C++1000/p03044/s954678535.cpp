#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

vector<P>E[200000];
int d[200000];

void dfs(int v,int p){
	for(auto u:E[v]){
		if(u.second!=p){
			d[u.second]=(d[v]+u.first)%2;
			dfs(u.second,v);
		}
	}
}

int main(){
	int n;cin>>n;
	rep(i,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);a--;b--;
		E[a].push_back(P(c,b));
		E[b].push_back(P(c,a));
	}
	dfs(0,-1);
	rep(i,n){
		printf("%d\n",d[i]);
	}
}