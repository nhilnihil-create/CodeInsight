#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    int h,w;cin >>h>>w;
    char a;
    vector<vector<ll>>turn(h,vector<ll>(w,INF));
    queue<P>now;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          cin >>a;
          if(a=='#') {
              turn[i][j] = 0;
              now.push({i, j});
          }
        }
    }
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    while(!now.empty()){
        P pos;
        pos=now.front();
        now.pop();
        ll ns=turn[pos.first][pos.second];
//        cout <<ns<<endl;
        for (int i = 0; i < 4; ++i) {
            int x=pos.first+dx[i];
            int y=pos.second+dy[i];
//            if(pos.first==0&&pos.second==1){
//                cout <<x<<" "<<y<<endl;
//            }
            if(x>=h||x<0)continue;
            if(y>=w||y<0)continue;
//            if(x==0&&y==0){
//                cout <<turn[x][y]<<" "<<ns+1<<endl;
//            }
            if(turn[x][y]>ns+1){
                now.push({x,y});
            }
            turn[x][y]=min(turn[x][y],ns+1);
        }
    }
    ll ans=0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
//            cout <<turn[i][j]<<" ";
            ans=max(ans,turn[i][j]);
        }
//        cout <<endl;
    }
    cout <<ans <<endl;
    return 0;
}

