#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll dx[4]={1,0,-1,0};
const ll dy[4]={0,1,0,-1};
int main() {
    ll h,w;
    cin >> h >> w;
    ll ans=0;
    vector<vector<char>>s(h,vector<char>(w));
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >>s[i][j];
            if(s[i][j]=='.') ans++;
        }
    }
    ll sx=0,sy=0,gx=h-1,gy=w-1;
    vector<vector<ll>>dist(h,vector<ll>(w,-1));
    dist[sx][sy]=0;

    queue<pair<ll,ll>>que;
    que.push({sx,sy});

    while(!que.empty()){
        pair<ll,ll> pos=que.front();
        ll x=pos.first;
        ll y=pos.second;
        que.pop();

        for(ll i=0;i<4;i++){
            ll nx=x+dx[i];
            ll ny=y+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(s[nx][ny]=='#') continue;

            if(dist[nx][ny]==-1){
                que.push({nx,ny});
                dist[nx][ny]=dist[x][y]+1;
            }
        }
    }
    ans-=(dist[gx][gy]+1);
    if(dist[gx][gy]==-1){
        cout << -1 << endl;
    }
    else cout << ans << endl;
}