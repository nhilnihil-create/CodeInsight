#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
const ll INF=1e9+7;
const ll N = 300003;

class UnionFind{
public:
	vector<int> par;
	//0-indexed
	void init(int n = 1) {
		par.resize(n);
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int root(int x = 1){
		if(par[x]==x)return x;
		else{
			return par[x] = root(par[x]);
		}
	}
	void unite(int x = 1,int y = 1){
		x = root(x);
		y = root(y);
		if(x==y)return;
		else par[x] = y;
	}
};
class dijkstra{ 
//0indexed 
public: 
	int v,startv; 
	vector<int> d; 
	vector<vector<pair<int,int> > >e; 

	void initsize(int n0){ 
		d.resize(n0); 
		for(int i=0;i<n0;i++)d[i]=INT_MAX; 
		vector<pair<int,int> > ep; 
		for(int i=0;i<n0;i++)e.push_back(ep); 
		v=n0; 
	} 

	void initstart(int s){ 
		startv=s;
		d[s]=0;
	}

	void make_edge(int x,int y,int cost){ 
		e[x].push_back(make_pair(y,cost)); 
		e[y].push_back(make_pair(x,cost)); 
	}

	void make_edgedir(int x,int y,int cost){ 
		e[x].push_back(make_pair(y,cost)); 
	}

	void calcdistance(){ 
		// <-cost,x> 
		//cost startv->x 
		priority_queue<pair<int,int> > q; 
		pair<int,int> p; 
		vector<bool> did; 
		for(int i=0;i<v;i++)did.push_back(false); 
		did[startv]=true; 
		for(int i=0;i<e[startv].size();i++){ 
			p.first=-e[startv][i].second; 
			p.second=e[startv][i].first; 
			q.push(p); 
		}
		while(q.size()!=0){
			pair<int,int> p;
			p=q.top();
			q.pop();
			int x,costsx;
			x=p.second;
			costsx=-p.first;
			if(did[x]==true)continue;
			did[x]=true;
			d[x]=costsx;
			for(int i=0;i<e[x].size();i++){
				p.first=-(d[x]+e[x][i].second);
				p.second=e[x][i].first;
				if(did[p.second]==false)q.push(p);
			}
		}
	}
};
int k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k;
	UnionFind uf;
	uf.init(k);
	dijkstra di;
	di.initsize(k);
	FOR(i,1,k){
		uf.unite(i,(i*10)%k);
	}
	di.initstart(uf.root(1));
	FOR(i,1,k){
		int x = uf.root(i);
		int y = uf.root((i+1)%k);
		if(x!=y)di.make_edgedir(x,y,1);
	}
	di.calcdistance();
	int g = uf.root(0);
	cout<<di.d[g]+1<<endl;
	return 0;
}
