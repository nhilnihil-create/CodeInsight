#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int H,W;
  cin>>H>>W;
  queue<pair<int,int>> q;
  vector<vector<bool>> seen(H,vector<bool>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      char c;
      cin>>c;
      if(c=='#') {
        q.push(make_pair(i,j));
        seen[i][j]=true;
      }
    }
  }
  int ans = -1;
  while(!q.empty()){
    queue<pair<int,int>> nq;
    int s = q.size();
    for(int i = 0; i < s;i++){
      pair<int,int>p=q.front();
      q.pop();
      for(int j = 0; j < 4; j++){
        int nx = p.first+dx[j];
        int ny = p.second+dy[j];
        if(nx>=H||nx<0||ny>=W||ny<0) continue;
        if(seen[nx][ny]) continue;
        seen[nx][ny]=true;
        nq.push(make_pair(nx,ny));
      }
    }
    q=nq;
    ans++;
  }
  cout<<ans<<endl;
}