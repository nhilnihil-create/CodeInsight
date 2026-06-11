#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i,H) cin >> A[i];
    vector<vector<int>> dist(H,vector<int>(W,-1));
    deque<pair<int,int>> dq;
    rep(i,H)rep(j,W){
        if(A[i][j]=='#'){
            dist[i][j]=0;
            dq.push_back(make_pair(i,j));
        }
    }
    while(!dq.empty()){
        int now_x = dq.front().second;
        int now_y = dq.front().first;
        dq.pop_front();
        for(int i=0;i<4;i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            if(nx<0||nx>=W||ny<0||ny>=H){
                continue;
            }
            if(dist[ny][nx]==-1){
                dist[ny][nx] = dist[now_y][now_x] + 1;
                dq.push_back(make_pair(ny,nx));
            }
        }
    }
    int ans = 0;
    rep(i,H)rep(j,W){
        ans = max(ans,dist[i][j]);
    }
    cout << ans << endl;
    return 0;
}