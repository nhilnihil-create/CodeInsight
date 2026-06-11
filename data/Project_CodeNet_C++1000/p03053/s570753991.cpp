#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;

int h,w;
char math[1010][1010];
vector<pair<int,int>> black;
bool flag = true;


int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

//BFS
int bfs(vector<vector<int>> depth){
    queue<pair<int,int>> que;
    int ans = 0;

    for(int i = 0; i < black.size(); i++){
        que.push(black[i]);
    }
 
    while(!que.empty()){
        pair<int,int> nw = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            if(0 <= nw.first+dy[i] && nw.first+dy[i] < h && 0 <= nw.second+dx[i] && nw.second+dx[i] < w){
                pair<int,int> nxt = make_pair(nw.first+dy[i],nw.second+dx[i]);
                if((depth[nxt.first][nxt.second] > depth[nw.first][nw.second]+1 || depth[nxt.first][nxt.second] == 0) && math[nxt.first][nxt.second] != '#'){
                    que.push(nxt);
                    depth[nxt.first][nxt.second] = depth[nw.first][nw.second]+1;
                    ans = max(ans,depth[nxt.first][nxt.second]);
                }
            }
        }
    }
    return ans;
}


int main(){
    cin >> h >> w;
    int cnt = 0;
    int ans = 0;
    vector<vector<int>> depth(h);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> math[i][j];
            if(math[i][j] == '#') black.push_back(make_pair(i,j));
            depth[i].push_back(0);
        }
    }

    cout << bfs(depth) << endl;
}