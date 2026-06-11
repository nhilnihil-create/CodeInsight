#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  cout << setprecision(10);

  int H,W;
  cin >> H >> W;
  vector<string> v(H);
  int INF = 100000;
  vector<vector<int>> check(H, vector<int>(W,INF));

  queue<pii> q;
  for(int i = 0; i < H; i++){
    cin >> v.at(i);
    for(int j = 0; j < W; j++){
      if(v.at(i).at(j) == '#'){
        q.push(make_pair(i,j));
        check[i][j] = 0;
      }
    }
  }
  int ans = 0;
  while(!q.empty()){
    pii now = q.front();
    int now_x = now.first;
    int now_y = now.second;
    q.pop();

    for(int k = 0; k < 4; k++){
      int next_x = now_x + dx[k];
      int next_y = now_y + dy[k];
      if(next_x >= 0 && next_x < H){
        if(next_y >= 0 && next_y < W){
          if(check[next_x][next_y] == INF){
            check[next_x][next_y] = check[now_x][now_y] + 1;
            q.push(make_pair(next_x,next_y));
            ans = max(ans, check[next_x][next_y]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
