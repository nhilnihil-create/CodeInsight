#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int N, M;
vector<int> a[50];
int visited[50] = {0};
pair<int, int> p[50];
int ngx, ngy;

void dfs(int x) {
  visited[x] = 1;
  for(int i = 0; i < a[x].size(); i++) {
    int nx = a[x][i];
    if((x == ngx && nx == ngy) || (x == ngy && nx == ngx)) continue;
    if(visited[nx] == 0) {
      dfs(nx);
    }
  }
}

int main() {
  cin >> N >> M;
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--;y--;
    a[x].push_back(y);
    a[y].push_back(x);
    p[i].first = x;
    p[i].second = y;
  }

  int ans = 0;

  for(int i = 0; i < M; i++) {
    ngx = p[i].first;
    ngy = p[i].second;
    dfs(p[i].first);
    bool f = false;
    rep(i, N) {
      if(visited[i] == 0) f = true;
    }
    if(f) ans++;
    rep(i, N) {
      visited[i] = 0;
    }
  }

  cout << ans << endl;

  return 0;
}