#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int n;
int a[300000];

class UnionFind {
public:
	vector<int>par, sz;
public:
	UnionFind() {}
	UnionFind(int n) {
		par = sz = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)return;
		par[x]=y;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return sz[find(x)];
	}
};
bool C(int t){
	unordered_map<int,int>mp,id,id_rev;
	set<int>se;
	UnionFind uf(n*3);
	int cnt=0;
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1])continue;
		int d=a[i];
		if(!id.count(d)){
			id[d]=cnt;cnt++;
			id_rev[id[d]]=d;
		}
		while(mp[d]==t){
			if(d==1){
				return false;
			}
			if(!id.count(d)){
				id[d]=cnt;cnt++;
				id_rev[id[d]]=d;
			}
			if(!id.count(d-1)){
				id[d-1]=cnt;cnt++;
				id_rev[id[d-1]]=d-1;
			}
			uf.unite(id[d],id[d-1]);
			int p=id[d];
			d=id_rev[uf.find(p)];
		}
		mp[d]++;
		se.insert(d);
		auto it=se.lower_bound(d+1);
		while(it!=se.end()){
			mp[*it]=0;
			uf.par[id[*it]]=id[*it];
			it=se.erase(it);
		}
	}
	return true;
}
int main(){
	scanf("%d",&n);
	bool flag=false;
	rep(i,n){
		scanf("%d",&a[i]);
		if(i&&a[i-1]>=a[i])flag=true;
	}
	if(!flag){
		puts("1");return 0;
	}
	int ok=n*2,ng=0;
	while(ok-ng>1){
		int t=(ok+ng)/2;
		if(C(t))ok=t;
		else ng=t;
	}
	cout<<ok+1<<endl;
}