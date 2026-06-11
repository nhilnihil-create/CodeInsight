#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int> P;

int di[] = {-1, 0, 0, 1};
int dj[] = { 0,-1, 1, 0};

int main(){
  int h,w;
  cin >> h >> w;
  
  vector<string> map(h);
  rep(i,h) cin >> map[i];
  
  queue<P> q;
  rep(i,h) rep(j,w) if(map[i][j] == '#') q.emplace(i,j);
  q.emplace(-1,-1);
  
  int ans = 0;
  while(1){
    int i = q.front().first;
    int j = q.front().second; q.pop();
    if(i == -1 && j == -1){
      if(q.empty()) break;
      ans++; q.emplace(-1,-1);
      continue;
    }
    rep(dir,4){
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(map[ni][nj] == '#') continue;
      map[ni][nj] = '#';
      q.emplace(ni,nj);
    }
  }
  cout << ans << endl;
  return 0;
}