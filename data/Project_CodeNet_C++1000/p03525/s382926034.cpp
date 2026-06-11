#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
vector<int> g[51];
vector<int> color(50);
vector<int> visit(50);
bool dfs(int v){
	for(int u:g[v]){
		if(visit[u] == 0){
            visit[u] = 1;
			color[u] = color[v] ^ 1;
			if(!dfs(u)) return false;
		}else{
			if(color[v] == color[u]) return false;
		}
	}return true;
}
int main(){
	int N;cin>>N;
	int D[N];
	rep(i,0,N) cin>>D[i];
	sort(D, D+N);
	for(int s = D[0]; s >= 0; s--){
		rep(i,0,N){ g[i].clear(); visit[i] = 0; }
		rep(i,0,N)rep(j,0,i){
			if(abs(D[i] - D[j]) < s){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		bool flag = true;
		rep(i,0,N)if(visit[i] == 0){
			visit[i] = 1;
			color[i] = 0;
			flag &= dfs(i);
		}
		int a = 0,b = 0;
		rep(i,0,N){
			if(color[i]) a = max(a, D[i]);
			else b = max(b, D[i]);
		}
		if(flag && abs(24 - a - b) >= s){ cout<<s<<endl; return 0; }
	}
}