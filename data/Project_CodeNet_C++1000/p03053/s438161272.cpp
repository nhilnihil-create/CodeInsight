#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  int H, W;
  cin >> H>> W;
  queue<pii> q;
  vector<vector<int>> d(H,vector<int>(W,-1));
  char s;
  rep(row,H){
    rep(col,W){
      cin >> s;
      if (s=='#'){
        q.push(make_pair(row,col));
        d.at(row).at(col) = 0;
      }
    }
  }

  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  
  while (!q.empty()){
    pii g = q.front(); q.pop();
    for (int i=0;i<4;i++){
      int nx = g.first+dx[i];
      int ny = g.second+dy[i];
      if (nx<0 || nx>=H || ny<0 || ny>=W) continue;

      if (d[nx][ny]==-1){
        d[nx][ny] = d[g.first][g.second]+1;
        q.push(make_pair(nx,ny));
      }

    }
    
  }

  int retval = 0;
  rep(row,H){
    rep(col,W){
      retval = max(retval,d.at(row).at(col));
    }
  }

  cout << retval << endl;
  
  return 0;
}
