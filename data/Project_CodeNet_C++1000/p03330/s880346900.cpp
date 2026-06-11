#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main(){
    int n,c;
    cin >> n >> c;
    ve<ve<int>> d(c,ve<int>(c));
    
    ve<ve<int>> x(3,ve<int>(c,0));
    rep(i,c)rep(j,c) cin >> d[i][j];
    rep(i,n)rep(j,n){
        int a;
        cin >> a;
        a--;
        x[(i+j)%3][a]++;
    }
    int ans = 2e9;
    rep(i,c)rep(j,c)rep(k,c){
        if(i==j||j==k||k==i)continue;
        int memo = 0;
        rep(a,c)memo += x[0][a]* d[a][i];
        rep(a,c)memo += x[1][a]* d[a][j];
        rep(a,c)memo += x[2][a]* d[a][k];
        chmin(ans,memo);
    }
    cout << ans << endl;
    return 0;
}
