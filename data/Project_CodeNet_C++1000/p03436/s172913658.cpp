#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int main(){
    int h, w, kuro=0;
    cin >> h >> w;
    int s[h][w];
    int dist[h][w];
    rep(i,h){
        rep(j,w){
            char x;
            cin >> x;
            if(x=='#'){
                s[i][j]=1;
                ++kuro;
            }else if(x=='.'){
                s[i][j]=2;
            }
            dist[i][j]=-1;
        }
    }
    queue<pair<int,int>> que;
    dist[0][0]=1;
    que.push({0,0});
    while(!que.empty()) {
        int u=que.front().first, v=que.front().second;
        que.pop();
        rep(i,4) {
            if(u+dy[i]<0 || v+dx[i]<0 || u+dy[i]>=h || v+dx[i]>=w) continue;
            if(dist[u+dy[i]][v+dx[i]]==-1 && s[u+dy[i]][v+dx[i]]==2) {
                dist[u+dy[i]][v+dx[i]] = dist[u][v] + 1;
                que.push({u+dy[i],v+dx[i]});
            }
        }
    }
    if(dist[h-1][w-1]==-1){
        cout << -1 << "\n";
        return 0;
    }
    cout << h*w-dist[h-1][w-1]-kuro << "\n";
    return 0;
}