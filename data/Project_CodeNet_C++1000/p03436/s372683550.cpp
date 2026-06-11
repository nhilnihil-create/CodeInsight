#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int d[50][50];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w) d[i][j] = 1e9;

  queue<P> q;
  auto push = [&](int i,int j,int nd){
    if(i<0||h<=i||j<0||w<=j) return;
    if(s[i][j]=='#') return;
    if(d[i][j]<=nd) return;
    d[i][j] = nd;
    q.emplace(i,j);
  };
  push(0,0,1);
  while(!q.empty()){
    P p = q.front(); q.pop();
    int i = p.first, j = p.second;
    rep(x,4) push(i+dx[x],j+dy[x],d[i][j]+1);
  }
  if(h*w < d[h-1][w-1]){
    cout << -1 << endl;
  }else{
    int ans = 0;
    rep(i,h)rep(j,w)if(s[i][j]=='.') ++ans;
    ans -= d[h-1][w-1];
    cout << ans << endl;
  }
}