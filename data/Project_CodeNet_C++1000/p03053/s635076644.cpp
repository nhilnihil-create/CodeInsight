#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;

int vx[4] = {0,1,0,-1};
int vy[4] = {1,0,-1,0};
int re[1002][1002];
queue<int> qx;
queue<int> qy;


void bfs(vector<vector<char>>& map){
    while(!qx.empty()){
        int x = qx.front();qx.pop();
        int y = qy.front();qy.pop();
        rep(i,4){
            int nx = x + vx[i];
            int ny = y + vy[i];
            if(re[nx][ny] != 0) continue;
            if(map[nx][ny] != '#'){
                re[nx][ny] = re[x][y] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);



    int h,w;
    cin >> h >> w;
    vector<vector<char>> map(h+2,vector<char> (w+2));
    rep(i,h+2)rep(j,w+2){
        map[i][j] = '#';
    }
    for(int i = 1;i < h+1;++i){
        for(int j = 1;j < w+1;++j){
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    bool flag = false;
    for(int i = 1;i < h+1;++i){
        for(int j = 1;j < w+1;++j){
            if(map[i][j] == '#'){
                qx.push(i);
                qy.push(j);
            }
        }
    }
    bfs(map);
    int ans = 0;
    for(int i = 1;i < h+1;++i){
        for(int j = 1;j< w+1;++j){
            ans = max(ans,re[i][j]);
        }
    }
    cout << ans << endl;

    cout << endl;
    return 0;
}
