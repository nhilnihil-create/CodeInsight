#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

//四方向への移動ベクトル
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> s(H);
  bool check = true;
  for (int i = 0; i < H; i++) cin >> s[i];
  for (int i = 0; i<H; i++){
      for(int j=0; j<W; j++){
        if (s[i][j] == '.') continue;
        bool next = false;
        for (int idx = 0; idx < 4; idx++) {
          ll next_x = j + dx[idx];
          ll next_y = i + dy[idx];
          if (next_y < 0 || next_y >= H || next_x < 0 || next_x >= W) continue;
          if (s[i][j] == s[next_y][next_x] && s[i][j] == '#') {
            next = true;
          }
        }
        if (!next) check = false;
      }
  }
  if (check) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}