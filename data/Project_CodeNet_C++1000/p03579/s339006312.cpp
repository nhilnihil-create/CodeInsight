#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct UnionFind {
    vector<int> par;
    UnionFind(int n) :par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool connect(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<vector<ll> > v(n);
    ll a,b;
    for(int i=0;i<m;i++){
    	cin >> a >> b;
    	a--;b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    vector<int> used(n,0);
    auto dfs = [&](auto&& dfs,int now) -> void{
    	used[now] = true;
    	ll niko = v[now][0];
    	for(auto& to:v[now]){
    		uf.connect(niko,to);
    		if(!used[to]) dfs(dfs,to);
    	}
    	return;
    };
    dfs(dfs,0);
    if(uf.size(0) == n){
    	cout << n*(n-1)/2 - m << endl;
    }else{
    	ll niko = uf.root(0);
    	ll maki;
    	for(int i=1;i<n;i++){
    		if(uf.root(i)!=niko){
    			maki = uf.root(i);
    			break;
    		}
    	}
    	niko=uf.size(niko);
    	maki=uf.size(maki);
    	cout << niko * maki - m << endl;
    }
    return 0;
}
