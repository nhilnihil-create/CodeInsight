#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(v) v.begin(), v.end()
#define revall(v) v.rbegin(), v.rend()
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }



struct UnionFind{
	vector<int> data;
	
	UnionFind(int n){
		data.assign(n,-1);
	}
	
	bool unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return(false);
		if(data[x]>data[y]) swap(x,y);
		data[x]+=data[y];
		data[y]=x;
		return(true);
	}
	
	int find(int k){
		if(data[k]<0) return(k);
		return(data[k]=find(data[k]));
	}
	
	int size(int k){
		return(-data[find(k)]);
	}
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	vector<int> p(n);
	rep(i,n){
		cin >> p.at(i);
		p.at(i)--;
	}
	UnionFind uf(n);
	rep(i,m){
		int x,y;cin >> x >> y;
		x--;y--;
		uf.unite(x,y);
	}
	int ans = 0;
	rep(i,n){
		if(p.at(i) == i) ans++;
		else if(uf.find(p.at(i)) == uf.find(i)) ans++;
	}
	cout << ans << endl;
}
