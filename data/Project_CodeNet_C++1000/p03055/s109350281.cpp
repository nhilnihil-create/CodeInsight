#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int n;
vector<int> G[200010];
int d[200010];

void dfs(int v, int prev, int dep){
    d[v] = dep;
    for(int nv: G[v])if(nv != prev) dfs(nv, v, dep+1);
    return;
}

int main(){
    scanf("%d", &n);
    rep(i, n-1){
        int a, b;
        scanf("%d%d", &a, &b);
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    
    rep(i, n) d[i] = -1;
    dfs(0, -1, 1);
    int v, dmax;
    dmax = 0;
    rep(i, n)if(d[i] > dmax){
        dmax = d[i];
        v = i;
    }
    
    rep(i, n) d[i] = -1;
    dfs(v, -1, 1);
    rep(i, n) dmax = max(dmax, d[i]);
    
    printf(dmax % 3 == 2 ? "Second\n" : "First\n");
}