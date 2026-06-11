#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,0,h) cin >> s[i];
  bool f = true;
  rep(i,0,h) rep(j,0,w) {
    if (s[i][j] == '.') continue;
    bool g = true;
    rep(k,0,4) {
      int ni = i + dx[k], nj = j + dy[k];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (s[ni][nj] == '#') g = false;
    }
    if (g) f = false;
  }
  if (f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
