#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
#define INF 1e7
typedef long long ll;
typedef long double ld;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> maze(h+2,vector<char> (w+2));
    vector<vector<int>> dist(h+2,vector<int> (w+2, INF));
    queue<pair<int,int>> que;
    REP(i,h+2)REP(j,w+2){
        if(i==0||j==0||i==h+1||j==w+1)continue;
        else{
            cin>>maze[i][j];
            if(maze[i][j]=='#'){
                que.push(make_pair(i,j));
                dist[i][j]=0;
            }
        }
    }
    vector<int> movel={1,-1,0,0}, movec={0,0,1,-1};
    while(!que.empty()){
        pair<int,int> p=que.front();
        int l=p.first, c=p.second;
        que.pop();
        REP(i,4){
            int nl=l+movel[i], nc=c+movec[i];
            if(maze[nl][nc]=='.'){
                maze[nl][nc]='#';
                dist[nl][nc]=dist[l][c]+1;
                que.push(make_pair(nl,nc));
            }
        }
    }
    int ans=0;
    FOR(i,1,h+1)FOR(j,1,w+1){
        if(ans<dist[i][j]){
            ans=dist[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
