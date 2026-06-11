#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

struct pnt{
    int cost, y, x;
};

vector<vector<int>> mv={{1,0},{-1,0},{0,1},{0,-1}};

int dist[1002][1002];
int bfs(queue<pnt> &que, vector<vector<char>> &mat){
    for(int i=0; i<1002; i++){
        for(int j=0; j<1002; j++){
            dist[i][j]=-1;
        }
    }

    while((int)que.size()>0){
        pnt p=que.front();
        que.pop();
        if(dist[p.y][p.x]>=0){
            continue;
        }
        dist[p.y][p.x]=p.cost;

        for(auto &m:mv){
            if(mat[p.y+m[0]][p.x+m[1]]=='.'){
                que.push({p.cost+1,p.y+m[0],p.x+m[1]});
            }
        }
    }

    int ans=0;
    for(int i=0; i<1002; i++){
        for(int j=0; j<1002; j++){
            ans=max(ans,dist[i][j]);
        }
    }
    return ans;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> mat(H+2,vector<char>(W+2,'@'));
    
    queue<pnt> que;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> mat[i][j];
            if(mat[i][j]=='#'){
                que.push({0,i,j});
            }
        }
    }

    cout << bfs(que, mat) << endl;

}