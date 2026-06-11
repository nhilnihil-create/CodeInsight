#include<bits/stdc++.h>
#define ll long long 
#define P pair<int,int>
using namespace std;
int inf = 1ll<<30;

int main(){
    int h,w;
    cin >> h >> w;
    char g[55][55];
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> g[i][j];
    vector<vector<int>> count(h,vector<int>(w));
    count[0][0] = 1;

    queue<P>que;
    que.push(P{0,0});
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    while(!que.empty()){
        P p = que.front();que.pop();
        int nx,ny;
        for(int i=0;i<4;i++){
            nx = p.first + dx[i];
            ny = p.second + dy[i];
            if(!(0 <=nx && 0 <= ny && h > nx && w > ny)) continue;
            if(g[nx][ny] == '#') continue;
            if(count[nx][ny])continue;
            count[nx][ny] = count[p.first][p.second] + 1;
            que.push(P{nx,ny});
        }
    }

    if(count[h-1][w-1] == 0){
        cout << "-1" << endl;
        return 0;
    }

    int sum = 0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        if(g[i][j] == '.') sum++;
    }

    cout << sum - count[h-1][w-1] << endl;

}