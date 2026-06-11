/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

#define MP make_pair

int n,m;
int a[200005];
bool v[200005];
vector<pair<int,int> > g[200005];
int mx,mn;

void dfs(int x){
	mn=min(a[x],mn);
	mx=max(a[x],mx);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i].first;
		if(v[y]){
			if(a[y]!=a[x]+g[x][i].second){
				cout<<"No";
				exit(0);
			}
		}else{
			v[y]=1;
			a[y]=a[x]+g[x][i].second;
			dfs(y);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,d;
		cin>>x>>y>>d;
		g[x].push_back(MP(y,d));
		g[y].push_back(MP(x,-d));  
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		mx=-1e9,mn=1e9;
		v[i]=1;
		a[i]=0;
		dfs(i);
		if(mx-mn>1e9){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
