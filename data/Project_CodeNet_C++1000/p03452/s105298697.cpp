#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define inf 1e13
typedef pair<int,int>P;
#define fi first
#define se second
int n,m,a,b,c;
int par[111111],ran[111111];
int f[111111];
bool used[111111];
vector<P>v[111111];
void init(int n){
	rep(i,n){
		par[i]=i;
		ran[i]=0;
	}
}
int find(int x){
	if(par[x]==x)return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(ran[x]<ran[y])par[x]=y;
	else{
		par[y]=x;
		if(ran[x]==ran[y])ran[x]++;
	}
}
bool bfs(int x){
	f[x]=0;
	queue<int>q;
	q.push(x);
	used[x]=false;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(P e:v[p]){
			if(f[e.fi]!=inf){
				if(f[e.fi]!=f[p]+e.se){
					return false;
				}
			}
			else{
				f[e.fi]=f[p]+e.se;
				q.push(e.fi);
				used[e.fi]=false;
			}
		}
	}
	return true;
}
signed main(){
	cin>>n>>m;
	init(n);
	fill(f,f+n,inf);
	fill(used,used+n,false);
	rep(i,m){
		cin>>a>>b>>c;
		a--,b--;
		unite(a,b);
		v[a].push_back({b,c});
		v[b].push_back({a,-c});
		used[a]=used[b]=true;
	}
	rep(i,n){
		if(used[i]){
			if(!bfs(i)){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
