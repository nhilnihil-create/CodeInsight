#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
const ll INF=1e18;
int N;
ll D[MAX_N];

map<ll,int> dmp;
int par[MAX_N],chl[MAX_N];
vector<int> G[MAX_N];
ll dist[MAX_N];
int main(){
	cin>>N;
	REP(i,N)cin>>D[i];
	REP(i,N){
		dmp[D[i]]=i;
	}
	REP(i,N){
		par[i]=-1;
		chl[i]=1;
	}
	bool flg=true;
	{
		auto ite=dmp.end();
		ite--;
		for(;;ite--){
			if (ite==dmp.begin()){
					break;
				}
//			cout<<ite->second<<endl;
			ll pd=ite->first-N+chl[ite->second]*2;
			if (pd>=ite->first || dmp.find(pd)==dmp.end()){
				flg=false;
				break;
			}
			int pr=dmp[pd];
			par[ite->second]=pr;
			chl[pr]+=chl[ite->second];
		}
	}
	if (flg){
//		cout<<"debug"<<endl;
		int rot;
		REP(i,N){
			if (par[i]==-1){
				rot=i;
			}else{
				G[i].push_back(par[i]);
				G[par[i]].push_back(i);
			}
		}
		queue<int > que;
		REP(i,N){
			dist[i]=INF;
		}
		que.push(rot);
		dist[rot]=0;
		while(!que.empty()){
			int v=que.front();
			que.pop();
			for(auto e:G[v]){
				if (dist[e]==INF){
					dist[e]=dist[v]+1;
					que.push(e);
				}
			}
		}
		ll sm=0;
		REP(i,N)sm+=dist[i];
		if (sm!=D[rot]){
			flg=false;
		}
	}
	if (flg){
		REP(i,N){
			if (par[i]!=-1){
				cout<<i+1<<" "<<par[i]+1<<endl;
			}
		}
	}else{
		cout<<-1<<endl;
	}
	return 0;
}