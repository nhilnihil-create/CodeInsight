#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N,C;
    cin >> N >> C;
    vec<vec<int>> D(C,vec<int>(C));
    rep(i,C)rep(j,C) cin >> D[i][j];
    vec<vec<int>> c(N,vec<int>(N));
    rep(i,N)rep(j,N) cin >> c[i][j],--c[i][j];

    vec<vec<int>> cost(3,vec<int>(C));
    rep(i,N)rep(j,N)rep(k,C){
        if(c[i][j] == k) continue;
        cost[(i+j+2)%3][k]+=D[c[i][j]][k];
    }
    
    int ans = 1e9;
    rep(i,C)rep(j,C)rep(k,C){
        if(i==j||i==k||j==k) continue;
        ans = min(ans,cost[0][i]+cost[1][j]+cost[2][k]);
    }
    cout << ans << endl;
}
