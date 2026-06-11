#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
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
T in(){ T x; cin >> x; return (x); }
template<typename T=ll,typename C=vector<T>>
C vecin(int N){ C x(N);REP(i,N){ x[i]=in<T>(); }return move(x); }

void vout(){ cout << endl; }
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){ cout << ' ' << h;vout(forward<Tail>(t)...); }
void out(){ cout << endl; }
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){ cout << h;vout(forward<Tail>(t)...); }

template<typename T>
bool chmax(T& a,T b){ if(a<b){ a=b;return true; }return false; }
template<typename T>
bool chmin(T& a,T b){ if(a>b){ a=b;return true; }return false; }

class UnionFind{
	vector<ll> rank;
	vector<ll> diff_weight;
	vector<ll> num;
public:
	vector<ll> par;

	UnionFind(ll N):par(N),num(N),rank(N),diff_weight(N){
		for(ll i=0;i<N;i++){
			par[i]=i;
			num[i]=1;
			rank[i]=0;
			diff_weight[i]=0;
		}
	}

	ll root(ll x){
		if(par[x]==x){
			return x;
		}
		ll r = root(par[x]);
		diff_weight[x]+=diff_weight[par[x]];
		return par[x]=r;
	}

	void unite(ll x,ll y){
		ll rx = root(x);
		ll ry = root(y);
		if(rx == ry) return;
		if(rank[rx]<rank[ry]) swap(rx,ry);
		if(rank[rx]==rank[ry]) ++rank[rx];
		par[ry] = rx;
		num[rx] += num[ry];
	}

	void relate(ll x,ll y,ll w){
		w+=weight(x),w-=weight(y);
		ll rx = root(x);
		ll ry = root(y);
		if(rx == ry) return;
		if(rank[rx]<rank[ry]){
			swap(rx,ry);
			w = -w;
		}
		if(rank[rx]==rank[ry]) ++rank[rx];
		par[ry] = rx;
		diff_weight[ry] = w;
		num[rx] += num[ry];
	}

	bool same(ll x,ll y){
		ll rx = root(x);
		ll ry = root(y);
		return rx == ry;
	}

	ll getsize(ll x){
		return num[root(x)];
	}

	ll weight(ll x){
		root(x);
		return diff_weight[x];
	}

	ll diff(ll x,ll y){
		return weight(y)-weight(x);
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in(),M=in();
	UnionFind uf(N);
	
	REP(i,M){
		int u=in()-1,v=in()-1,z=in();
		uf.unite(u,v);
	}
	unordered_set<ll> S;
	REP(i,N){
		S.insert(uf.root(i));
	}
	out(S.size());
	return 0;
}
