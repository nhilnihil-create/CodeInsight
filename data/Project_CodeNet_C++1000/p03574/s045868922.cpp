#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  vector<vector<char>> ans(h,vector<char>(w));
  rep(i,h) cin >> s[i];
  rep(i,h){
    rep(j,w){
      int now=0;
      rep(k,8){
        if(i + dy[k] < 0 || i + dy[k] >= h || j + dx[k] < 0 || j + dx[k] >= w) continue;
				if(s[i+dy[k]][j+dx[k]] == '#') now++;
      }
      ans[i][j]=now+'0';
    }
  }
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='#')
        cout << '#';
      else cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
