#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddNonDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	void AddDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){return graph.size();}
};

void DFS(ConnectNodeInfo& connection,ll child,ll parent,vector<ll>& C,vector<ll>& V,ll& cnt,ll& score){
	for(int i = 0;i < connection[child].size();i++){
		if(connection[child][i].first != parent){
			ll nc = connection[child][i].first;
			V[nc] = C[cnt++];
			score += min(V[child],V[nc]);
			DFS(connection,nc,child,C,V,cnt,score);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in();
	ConnectNodeInfo connect(N);
	REP(i,N-1){
		int u=in()-1,v=in()-1;
		connect.AddNonDirectionalConnection(u,v,1);
	}
	vector<ll> C=vecin<ll>(N);
	sort(ALL(C),greater<ll>());

	vector<ll> V(N,0);
	V[0] = C[0];
	ll cnt = 1;
	ll score = 0;
	DFS(connect,0,-1,C,V,cnt,score);

	out(score);
	PRINTALL(V);
	return 0;
}
