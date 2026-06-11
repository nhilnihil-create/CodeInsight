#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int h,w;
int dx[8] = {1,0,-1,1,-1,1,0,-1};
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int countsh(vector<vector<char>> &G,int y,int x){
    int cnt = 0;
    for(int i = 0;i <= 7;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || nx >= w || ny >= h) continue;
        if (G[ny][nx] == '#') cnt++;
    }

    return cnt;
}

int main(){
    
    cin >> h >> w;
    vector<vector<char>> g;
    g.assign(h,vector<char>(w,'.'));
    rep(i,h)rep(j,w) cin >> g[i][j];

    rep(i,h){
        rep(j,w){
            if(g[i][j]=='#') cout<<'#';
            else cout <<countsh(g,i,j);
        }
        cout <<endl;
    }
}