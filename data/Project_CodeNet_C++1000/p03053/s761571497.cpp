#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int ni[] = {-1, 0, 1, 0};
int nj[] = {0, -1, 0, 1};

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];

  queue<pair<int, int>> q;
  rep(i,h) rep(j,w) if(a[i][j] == '#') q.emplace(i,j);

  int ans = 0;
  while(!q.empty()){ 
    queue<pair<int, int>> t;
    while(!q.empty()){
      int si = q.front().first;
      int sj = q.front().second;
      q.pop();
      rep(i,4){
        int x = si + ni[i];
        int y = sj + nj[i];
        if (x < 0 || y < 0 || x >= h || y >= w) continue;
        if (a[x][y] == '.'){
          a[x][y] = '#';
          t.emplace(x,y);
        }
      }
    }
    q = t;
    if(!q.empty()) ans++;
  }
  cout << ans << endl;

  return 0;
}
