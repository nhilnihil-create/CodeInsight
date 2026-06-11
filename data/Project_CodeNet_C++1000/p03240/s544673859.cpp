#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N), h(N);
  for (int i=0; i<N; i++) cin >> x[i] >> y[i] >> h[i];
  bool exist = false; // 高さが0でないものが存在するか
  for (int i=0; i<N; i++) {
    if (h[i]!=0) {
      exist = true;
      break;
    }
  }
  if (exist) {
    // 中心座標を全探索
    for (int Cx=0; Cx<=100; Cx++) {
      for (int Cy=0; Cy<=100; Cy++) {
        int H = 0;
        for (int i=0; i<N; i++) {
          if (h[i]!=0) {
            H = abs(x[i]-Cx)+abs(y[i]-Cy)+h[i];
            break;
          }
        }
        bool pos = true;
        for (int i=0; i<N; i++) {
          if (max(H-abs(x[i]-Cx)-abs(y[i]-Cy), 0)!=h[i]) {
            pos = false;
            break;
          }
        }
        if (pos) {
          cout << Cx << " " << Cy << " " << H << endl;
          return 0;
        }
      }
    }
  }
  else {
    int H = 1;
    for (int Cx=0; Cx<=100; Cx++) {
      for (int Cy=0; Cy<=100; Cy++) {
        bool pos = true;
        for (int i=0; i<N; i++) {
          if (max(H-abs(x[i]-Cx)-abs(y[i]-Cy), 0)!=h[i]) {
            pos = false;
            break;
          }
        }
        if (pos) {
          cout << Cx << " " << Cy << " " << H << endl;
          return 0;
        }
      }
    }
  }
}