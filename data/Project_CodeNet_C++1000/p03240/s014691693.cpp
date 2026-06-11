#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  vector<vector<int>> v(n, vector<int>(3));
  for (int i = 0; i < n; ++i){
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }

  int Cx, Cy, H_a=0;

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      int H = 0;
      for (int idx = 0; idx < n; idx++) {
        int x = v[idx][0], y = v[idx][1], h = v[idx][2];
        if(h==0) continue;
        H = h + abs(x - i) + abs(y - j);
        break;
      }
      for (int idx = 0; idx<n; idx++){
        int x = v[idx][0], y = v[idx][1], h = v[idx][2];
        if(h!=max(H-abs(i-x)-abs(j-y), 0)) break;
        if(idx==n-1){
          Cx = i;
          Cy = j;
          H_a = H;
          cout << Cx << ' ' << Cy << ' ' << H_a << endl;
        }
      }
    }
  }
  return 0;
}
