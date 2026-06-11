#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return x;}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto H=in(),W=in(),D=in();
	vll MI(H*W),C(H*W,0);
	REP(i,H){
		REP(j,W){
			MI[in()-1] = j+i*W;
		}
	}
	REP(i,H*W){
		if(i+D<H*W){
			ll u=MI[i]%W,v=MI[i]/W;
			ll x=MI[i+D]%W,y=MI[i+D]/W;
			C[i+D] += C[i]+abs(u-x)+abs(v-y);
		}
	}

	auto Q=in();
	LOOP(Q){
		auto L=in()-1,R=in()-1;
		out(C[R]-C[L]);
	}
	return 0;
}
