#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=200010;
char col[maxn];
vector<int> g[maxn];
int acnt[maxn],bcnt[maxn];
bool vis[maxn];
int main(){
	int n,m,u,v;
	scanf("%d%d%s",&n,&m,col+1);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	queue<int> q;
	for(int u=1;u<=n;u++){
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(col[v]=='A') acnt[u]++;
			else bcnt[u]++;
		}
		if(acnt[u]==0 || bcnt[u]==0){
			q.push(u);
			vis[u]=true;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if(!vis[v]){
				if(col[u]=='A') acnt[v]--;
				else bcnt[v]--;
				if(acnt[v]==0 || bcnt[v]==0){
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	bool found=false;
	for(int v=1;v<=n;v++)
		if(!vis[v]) found=true;
	puts(found?"Yes":"No");
	return 0;
}