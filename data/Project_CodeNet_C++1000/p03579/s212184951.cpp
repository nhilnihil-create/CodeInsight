#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;

lint n, m;
vector<int> G[100010];
int c[100010];

bool dfs(int v, int t){
    if(c[v] >= 0) return c[v] == t ? true : false;
    c[v] = t;
    for(int nv : G[v]){
        if(!dfs(nv, t^1)) return false;
    }
    return true;
}

int main(){
    scanf("%lld%lld", &n, &m);
    rep(i, m){
        int a, b;
        scanf("%d%d", &a, &b);
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    rep(i, n) c[i] = -1;
    if(dfs(0, 0)){
        lint c1 = 0;
        lint c2 = 0;
        rep(i, n){
            if(c[i]) ++c1;
            else ++c2;
        }
        printf("%lld\n", c1*c2 - m);
    }
    else printf("%lld\n", n*(n-1)/2 - m);
}