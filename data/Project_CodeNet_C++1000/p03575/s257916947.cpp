#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n,m,eu,ev,low[60],dfn[60],clo,answer;
vector<int> ga[60];
void tarjan(int u,int par){
	dfn[u]=++clo;
	low[u]=dfn[u];
	for(int v:ga[u]){
		if(v==par) continue;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) answer++;
}
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	while(m--){
		cin>>eu>>ev;
		ga[eu].push_back(ev);
		ga[ev].push_back(eu);
	}
	tarjan(1,-1);
	cout<<answer-1<<endl;
	return 0;
}
