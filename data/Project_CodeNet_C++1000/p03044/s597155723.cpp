#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int, int> pii;
typedef long long ll;

void C(){
	/**int pass(int m, int k){
		int cnt=0;
		while(m<k){
			m*=2;
			cnt++;
		}
		return cnt;
	}
	int n,k; cin>>n>>k;
	double ans=0;
	for(int i=1; i<=n; i++){
		int x = 1<<pass(i, k);
		double prob = 1.0/(x*1.0);
		ans+=((1.0/n*1.0)*prob);
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;*/
}
const int MAX = 1e5+1;
vector<pii> g[MAX];
bool vis[MAX];
int color[MAX];

void D(){
/**void dfs(pii u){
	vis[u.F] = 1;
	for(auto&x: g[u.F]){
		if(!vis[x.F]){
			if(x.S%2==0){
				if(color[u.F]!=-1)color[x.F]=color[u.F];
				else color[x.F]=color[u.F]=0;
			}
			else color[x.F]=!color[u.F];
			dfs(x);
		}
	}
}*/
}
void bfs(pii u){
	memset(color, -1, sizeof(color));
	queue<pii> q;
	q.push(u);
	while(!q.empty()){
		pii v = q.front();
		q.pop();
		vis[v.F]=true;
		for(auto&x: g[v.F]){
			if(!vis[x.F]){
				vis[x.F]=true;
				if(x.S%2==0){
					if(color[v.F]!=-1)color[x.F]=color[v.F];
					else color[v.F]=color[x.F]=0;
				}
				else{
					//color[v.F]=!color[x.F];
					if(color[v.F]!=-1)color[x.F]=!color[v.F];
					else {color[v.F]=0; color[x.F]=1;}
				}
				q.push(x);
			}
		}
	}
}

int main(){
	int n; cin>>n;
	int u, v, w;
	for(int i=0; i<n-1; i++){
		cin>>u>>v>>w;
		u--; v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	bfs({0,0});
	for(int i=0; i<n; i++){
		cout<<color[i]<<endl;
	}
	return 0;   
}
