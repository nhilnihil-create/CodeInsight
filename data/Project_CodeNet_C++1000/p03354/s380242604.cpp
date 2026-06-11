#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;



struct UnionFind {
	vector<int> par;
	vector<int> rank;

	UnionFind(int n) : par(n), rank(n) { 
		for(int i = 1; i <= n; i++) {par[i] = i; rank[i] = 0;}
	}

	int find(int x) {if (par[x]==x) return x; else return par[x] = find(par[x]);}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x==y) return;

		if (rank[x]>rank[y]) par[y] = x;
		else {par[x] = y; if (rank[x]==rank[y]) rank[y]++;}
	}
	bool same(int x, int y) {return find(x)==find(y);}
};

int ans, N, M;
int p[100005];

int main(void) {
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%d", &p[i]);
    
    UnionFind uf(100005);
    
    for (int i=0; i<M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        uf.unite(x, y);
    }

    for(int i=1; i<=N; i++) if (uf.same(i, p[i])) ans++;
    
   
    printf("%d\n", ans);

	return 0;
}
