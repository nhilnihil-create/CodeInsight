#include<bits/stdc++.h>
#define ll long long 
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;
int inf = 1ll<<30;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int h,w;
    cin >> h >> w;
    char g[1005][1005];
    queue<PP>que;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) {
        cin >> g[i][j];
        if(g[i][j] == '#') que.push(PP{P{i, j}, 0});
    }

    int ans;
    while(!que.empty()){
        PP p = que.front(); que.pop();
        ans = p.second;
        for(int i=0;i<4;i++){
            int nx = p.first.first + dx[i];
            int ny = p.first.second + dy[i];
            if(!(0 <= nx && 0 <= ny && h > nx && w > ny)) continue;
            if(g[nx][ny] == '#') continue;
            g[nx][ny] = '#';
            que.push(PP{P{nx, ny}, ans + 1});
        }
    }

    cout << ans << endl;

}