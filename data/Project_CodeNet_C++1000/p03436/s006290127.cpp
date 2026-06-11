#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using QP = queue<pair<int, int>>;

int main(){
  int H, W;
  cin >> H >> W;
  string s;
  vector<string> S(H+2, string(W+2, '#'));
  int cnt = 0;
  rep(h, H){
    cin >> s;
    S[h+1] = '#' + s + '#';
    for(auto x: S[h+1]) if (x == '.') cnt++;
  }
  int I[H+2][W+2] = {};
  QP Q;
  Q.push(make_pair(1, 1));
  I[1][1] = 1;
  int h, w, nh, nw;
  int dh[4] = {1, 0, -1, 0};
  int dw[4] = {0, 1, 0, -1};
  while (!Q.empty()){
    h = Q.front().first;
    w = Q.front().second;
    Q.pop();
    rep(i, 4){
      nh = h + dh[i];
      nw = w + dw[i];
      if (S[nh][nw] == '.' && I[nh][nw] == 0){
        Q.push(make_pair(nh, nw));
        I[nh][nw] = I[h][w] + 1;
      }
    }
  }
  int ans = (I[H][W]) ? cnt - I[H][W]: -1;
  cout << ans << endl;
  return 0;
}
