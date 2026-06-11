#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int x,y,W;

void move_grid(){
    if(y%2==0){
        if(x+1<W){
            // 右に進む
            x++;
        }else{
            // 下に進む
            y++;
        }
    }else{
        if(x-1>=0){
            // 左に進む
            x--;
        }else{
            // 下に進む
            y++;
        }
    }
}

int main(){
    int H;
    cin >> H >> W;
    vector<vector<int>> G(H,vector<int>(W));
    rep(i,H)rep(j,W){
        cin >> G[i][j];
    }
    ll cnt = 0;
    x=0;
    y=0;
    ll ans = 0;
    vector<pair<int,int>> mv[2];
    while(true){
        cnt++;
        if(cnt==H*W) break;
        if(G[y][x]%2==1){
            ans++;
            mv[0].push_back(make_pair(y+1,x+1));
            move_grid();
            mv[1].push_back(make_pair(y+1,x+1));
            G[y][x]++;
        }else{
            move_grid();
        }
    }
    cout << ans << endl;
    rep(i,ans){
        cout << mv[0][i].first << " " << mv[0][i].second << " ";
        cout << mv[1][i].first << " " << mv[1][i].second << endl;;
    }
    return 0;
}