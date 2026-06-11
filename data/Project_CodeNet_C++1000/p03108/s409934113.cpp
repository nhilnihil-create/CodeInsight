#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double EPS=1e-10;
const double PI=acos(-1);

//全ての要素に対して自身が根となるように初期化, 木の深さは0になる
struct UnionFind{
public:
	vector<int> par;
	vector<int> rank;
	vector<int> s;
	int cnt;
 
	UnionFind(int n){
		rep(i,n){
			par.push_back(i);
			rank.push_back(0);
			s.push_back(1);
		}
		cnt=n;
	}
 
	int find(int x){
		if(par[x]==x) return x;
		else return par[x]=find(par[x]);
	}
 
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]){
			par[x]=y;
			s[y]+=s[x];
		}else{
			par[y]=x;
			s[x]+=s[y];
			if(rank[x]==rank[y]) rank[x]++;
		}
		cnt--;
	}

	bool same(int x,int y){
		return find(x)==find(y);
	}

	int size(int x){
		return s[find(x)];
	}
};

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	UnionFind uf(n);
	vector<ll> a(m),b(m);
	rep(i,m){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
	}
	ll ans=n*(n-1)/2;
	vector<ll> now;
	for(int i=m-1;i>=0;i--){
		now.push_back(ans);
		if(uf.same(a[i],b[i])) continue;
		ll sz1=uf.size(a[i]),sz2=uf.size(b[i]);
		ans-=sz1*sz2;
		uf.unite(a[i],b[i]);
	}
	reverse(begin(now),end(now));
	cout<<now<<endl;
}