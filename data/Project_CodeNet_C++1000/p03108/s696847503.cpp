#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int N, M;
vector<P> edges;
vector<int> ans;

struct Unionfind {
    vector<int> par, rank;
    
    Unionfind(int n) {
        par.resize(n);
        fill(par.begin(), par.end(), -1);
        rank.resize(n);
    }
    
    int root(int x) {
        int r = x;
        while (!(par[r]<0)) r = par[r];
        int t = x;
        
        while (t!=r) {
            int tmp = t;
            t = par[t];
            par[tmp] = r;
        }
        
        return r;
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        
        if (rx==ry) return;
        
        if (rank[rx]<=rank[ry]) {
            par[ry] += par[rx];
            par[rx] = ry;
            
            if (rank[rx]==rank[ry]) rank[ry]++;
        }
        else {
            par[rx] += par[ry];
            par[ry] = rx;
        }
    }
    
    bool is_same(int x, int y) {
        return root(x)==root(y);
    }
    
    int count(int x) {
        return -par[root(x)];
    }
};

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, M) {
        int A, B; cin >> A >> B;
        edges.pb(P(A-1, B-1));
    }
    
    Unionfind uf(N);
    int inconv = N*(N-1)/2;
    ans.pb(inconv);
    for (int i=M-1; i>=0; i--) {
        int A = edges[i].first, B = edges[i].second;
        if (!uf.is_same(A, B)) {
            int ac = uf.count(A);
            int bc = uf.count(B);
            inconv -= ac*bc;
            uf.unite(A, B);
        }
        ans.pb(inconv);
    }
    reverse(ans.begin(), ans.end());
    for (int i=1; i<=M; i++) cout << ans[i] << endl;
}