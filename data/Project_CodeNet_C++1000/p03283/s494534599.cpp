#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    
    ve<ve<int>> lr(n+2,ve<int>(n+2,0));
    rep(i,m){
        int l,r;
        cin >> l >> r;
        lr[l][r]++;
    }
    rep(i,n+1)rep(j,n+1) lr[i][j+1] += lr[i][j];
    rep(i,n+1)rep(j,n+1) lr[j+1][i] += lr[j][i];

    rep(Q,q){
        int p,q;
        cin >> p >> q;
        int ans =  lr[q][q] + lr[p-1][p-1] - lr[p-1][q] - lr[q][p-1];
        printf("%d\n", ans);
    }
    return 0;
}
