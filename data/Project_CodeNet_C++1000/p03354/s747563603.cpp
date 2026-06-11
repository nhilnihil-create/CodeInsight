#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};

struct UnionFind {
    vector<int> par; 
    vector<int> sizes;
    UnionFind(int N) : par(N),sizes(N,1) { 
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return; 
        if (sizes[rx]<sizes[ry])swap(rx,ry);
        // xがyの親になるように連結する
        par[ry] = rx; 
        sizes[rx]+=sizes[ry];
    }

    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    
    int size(int x){
        return sizes[root(x)];
    }

};

int ans;
int n,m;
int a[111111];
int x[111111],y[111111];

signed main(){
    
    
    cin>>n>>m;
    UnionFind uf(n+2);
    rep(i,n){
    	cin>>a[i];
    	a[i]--;
    }
    rep(i,m){
    	cin>>x[i]>>y[i];
    	x[i]--;y[i]--;
    	uf.unite(x[i],y[i]);
    }
    
    rep(i,n){
    	if(uf.same(i,a[i]))ans++;
    }
    cout<<ans<<endl;

}