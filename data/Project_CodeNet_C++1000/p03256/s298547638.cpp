#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define rng(i,l,r) for(int i=int(l);i<int(r);i++)
#define rep(i,r) rng(i,0,r)
#define rrng(i,l,r) for(int i=int(r)-1;i>=int(l);i--)
#define rrep(i,r) rrng(i,0,r)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#define inf INT_MAX/2-100
#define infl LLONG_MAX/3
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<' '<<#x<<' '<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u>void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u>void chmin(t&a,u b){if(b<a)a=b;}

template<class t>using vc=vector<t>;
template<class t>using vvc=vector<vector<t>>;

using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vi=vc<int>;
using vl=vc<ll>;


ll readl(void){
	ll x;
	cin>>x;
	return x;
}
int readi(void){
	int x;
	cin>>x;
	return x;
}

string readstr(){
	string s;
	cin>>s;
	return s;
}
vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=readi(),v[i]+=off;
	return v;
}

vl readvl(int n,int off=0){
	vl v(n);
	rep(i,n)v[i]=readl(),v[i]+=off;
	return v;
}

template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)cout<<"\n";
	if(suc==2)cout<<" ";
}

template<class t>
void print(const vc<t>&v,int suc=1){
	rep(i,si(v))print(v[i],i==int(si(v))-1?1:suc);
}

template<class t>
bool inc(t a,t b,t c){
	return !(c<b||b<a);
}

template<class t>
void compress(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}

template<class t>
struct Compress{
	vc<t>v;
	Compress()=default;
	Compress(const vc<t>&x){
		add(x);
	}
	Compress(const initializer_list<vc<t> >&x){
		for(auto &p:x)add(p);
	}
	void add(const t&x){
		v.eb(x);
	}
	void add(const vc<t>&x){
		copy(all(x),back_inserter(v));
	}
	void build(){
		compress(v);
	}
	int get(const t&x)const{
		return lwb(v,x);
	}
	vc<t>get(const vc<t>&x)const{
		vc<t>res(x);
		for(auto &p:res)p=get(p);
		return res;
	}
	const t &operator[](int x)const{
		return v[x];
	}
};
void Yes(bool ex=true){
	cout<<"Yes\n";
	if(ex)exit(0);
}
void YES(bool ex=true){
	cout<<"YES\n";
	if(ex)exit(0);
}
void No(bool ex=true){
	cout<<"No\n";
	if(ex)exit(0);
}
void NO(bool ex=true){
	cout<<"NO\n";
	if(ex)exit(0);
}
void orYes(bool x,bool ex=true){
	if(x)Yes(ex);
	else No(ex);
}
void orYES(bool x,bool ex=true){
	if(x)YES(ex);
	else NO(ex);
}
void Possible(bool ex=true){
	cout<<"Possible\n";
	if(ex)exit(0);
}
void POSSIBLE(bool ex=true){
	cout<<"POSSIBLE\n";
	if(ex)exit(0);
}
void Impossible(bool ex=true){
	cout<<"Impossible\n";
	if(ex)exit(0);
}
void IMPOSSIBLE(bool ex=true){
	cout<<"IMPOSSIBLE\n";
	if(ex)exit(0);
}
void orPossible(bool x,bool ex=true){
	if(x)Possible(ex);
	else Impossible(ex);
}
void orPOSSIBLE(bool x,bool ex=true){
	if(x)POSSIBLE(ex);
	else IMPOSSIBLE(ex);
}

template<class T>
struct Edge{
	int s,t;
	T c;
	Edge(int x,T y):s(-1),t(x),c(y){}
	Edge(int x,int y,T z):s(x),t(y),c(z){}
};

template<class T>
using Edges=vector<Edge<T> >;
template<class T>
using Graph=vector<Edges<T> >;


template<class T>
bool dfsforTopologicalsort(const Graph<T>&g,int v,vector<int>&order,vector<int>&vis){
	vis[v]=1;
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i].t;
		if(vis[u]==2)continue;
		if(vis[u]==1)return false;
		if(!dfsforTopologicalsort(g,u,order,vis))return false;
	}
	order.emplace_back(v);
	vis[v]=2;
	return true;
}

template<class T>
bool Topologicalsort(const Graph<T>&g,vector<int>&order){
	int n=g.size();
	vector<int>vis(n);
	for(auto &i:vis)i=0;
	for(int i=0;i<n;i++){
		if(vis[i]==0&&!dfsforTopologicalsort(g,i,order,vis))return false;
	}
	reverse(order.begin(),order.end());
	return true;
}
int n,m;
string s;
Graph<int>g;
void mk(int x,int y){
	g[x].eb(y,0);
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	g.resize(n*2);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(s[a]==s[b]){
			mk(a*2,b*2+1);
			mk(b*2,a*2+1);
		}else{
			mk(a*2+1,b*2);
			mk(b*2+1,a*2);
		}
	}
	vi k;
	if(!Topologicalsort(g,k))Yes();
	else No();
}
