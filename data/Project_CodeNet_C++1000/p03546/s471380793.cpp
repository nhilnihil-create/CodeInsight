#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define N 10
#define H 10
#define W 10

const lli INF = 1e9;
lli h, w;
vector<vector<lli>> c(H, vector<lli>(W));

void warshal_floyd(int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }
}

int main(void){
    cin >> h >> w;
    rep(i, H) rep(j, W) cin >> c[i][j];
    warshal_floyd(N);
    lli ans = 0;
    rep(i, h) rep(j, w) {
        int a;
        cin >> a;
        if(a == -1) continue;
        ans += c[a][1];
    }
    cout << ans << endl;
    return 0;
}
