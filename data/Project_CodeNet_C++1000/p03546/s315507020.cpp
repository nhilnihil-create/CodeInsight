#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF=(1LL<<31)-1;

ll cost[11][11];
int wall[300][300];


int main(){
    int H,W; cin >> H >> W;
    rep(i,10){
        rep(j,10){
            cin >> cost[i][j];
        }
    }
    rep(x,H){
        rep(y,W){
            cin >> wall[x][y];
        }
    }


    rep(k,10){
        rep(i,10){
            rep(j,10){
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
    ll res = 0;
    rep(x,H){
        rep(y,W){
            if(wall[x][y]!=-1 && wall[x][y]!=1) res += cost[wall[x][y]][1];
        }
    }
    cout << res << endl;
}