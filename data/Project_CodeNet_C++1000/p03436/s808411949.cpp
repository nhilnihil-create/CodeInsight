#include <algorithm>
#include <iostream> //標準入出力
#include <fstream>  //ファイルでの入出力
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <utility> //pair
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000000
#define pair(a) pair<a,a>

int bfs(vector<string>& field,int fb){
    int h=field.size(),w=field[0].size();
    vector<vector<int>> dfroms(h,vector<int>(w,200000));
    queue<pair(int)> later;
    const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0}; //東西南北の順

    later.push({0,0});
    dfroms[0][0] = 1;

    while(!later.empty()){
        pair(int) now = later.front();
        int x = now.first, y = now.second;
        later.pop();
        rep(i,4){
            pair(int) next = {x+dx[i],y+dy[i]};
            int nx = next.first,ny = next.second;
            if(nx<0||nx>=h||ny<0||ny>w) continue;
            if(field[nx][ny]=='#') continue;
            if(dfroms[nx][ny]!=200000) continue;
            dfroms[nx][ny] = dfroms[x][y] + 1;
            later.push(next);
        }
    }
    int out = h*w - dfroms[h-1][w-1] - fb;
    if(dfroms[h-1][w-1] == 200000) return -1;
    else return out;
}

void _main(){
    int h,w;
    cin >> h >> w;
    vector<string> field; 
    field.resize(h);
    rep(i,h) cin >> field[i];
    int firstblack = 0;
    rep(i,h) rep(j,w) if(field[i][j]=='#') firstblack++;
    cout << bfs(field,firstblack) << endl;
    
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    