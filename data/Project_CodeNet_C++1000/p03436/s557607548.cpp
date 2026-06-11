#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
#define INF 1e5
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> maze(h+2,vector<char>(w+2));
    vector<vector<int>> dist(h+2, vector<int>(w+2, INF));
    int white=0;
    REP(i,h+2)REP(j,w+2){
        if(i*j==0||i==h+1||j==w+1)maze[i][j]='#';
        else{
            cin>>maze[i][j];
            if(maze[i][j]=='.')white++;
        }
    }
    vector<int> movel={1,-1,0,0}, movec={0,0,1,-1};
    queue<pair<int,int>> que;
    que.push(make_pair(1,1));
    dist[1][1]=0;
    while(!que.empty()){
        pair<int,int> now=que.front();
        que.pop();
        int l=now.first, c=now.second;
        REP(i,4){
            int nextl=l+movel[i], nextc=c+movec[i];
            if(maze[l][c]=='.'&&dist[nextl][nextc]>dist[l][c]+1){
                dist[nextl][nextc]=dist[l][c]+1;
                que.push(make_pair(nextl, nextc));
            }
        }
    }
    int ans;
    if(dist[h][w]!=INF){
        ans=white-dist[h][w]-1;
    }else{
        ans=-1;
    }
    cout<<ans<<endl;
    return 0;
}
