#include<bits/stdc++.h>
using namespace std;

const int N = 100007;

vector< pair<int,int> > g[N];
bool ok = 1;
bool vis[N];
vector<int> A(N);

void dfs(int x){
	vis[x] = 1;

	for(int i = 0; i < (int)g[x].size();i++){
		int to = g[x][i].first;
		int len = g[x][i].second;
		if(!vis[to]){
			A[to] = A[x]+len;
			dfs(to);
		} else {
			if(A[to]!=A[x]+len) ok = 0;
		}
	}
}

int main(){
	
	int n,m;
	cin>>n>>m;

	for(int i = 0;i<m;i++){
		int l,r,d;
		cin>>l>>r>>d;
		g[l].push_back(make_pair(r,d));
		g[r].push_back(make_pair(l,-d));
	}

	for(int i = 1;i < n;i++){
		if(!vis[i]) dfs(i);
	}
	if(ok) cout<<"Yes";
	else cout<<"No";
}