#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

ll pre[3][30];

int main() {
    int n,C;
    cin>>n>>C;
    int d[33][33],c[510][510];
    rep(i,C){
        rep(j,C){
            cin>>d[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            cin>>c[i][j];
            c[i][j]--;
        }
    }

    rep(col,C){
        rep(i,n){
            rep(j,n){
                pre[(i+j)%3][col]+=d[c[i][j]][col];
            }
        }
    }

    ll ans=INF;
    for(int r0=0;r0<C;r0++){
        for(int r1=0;r1<C;r1++){
            for(int r2=0;r2<C;r2++){
                if(r0==r1 || r0==r2 || r1==r2) continue;
                ans=min(ans,pre[0][r0]+pre[1][r1]+pre[2][r2]);
            }
        }
    }

    cout<<ans<<endl;
}