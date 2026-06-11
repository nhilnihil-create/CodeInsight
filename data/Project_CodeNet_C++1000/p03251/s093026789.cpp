#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> vx(n), vy(m);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }
  
  for (int i = 0; i < m; ++i) {
    cin >> vy[i];
  }
  
  int max_x = *max_element(vx.begin(), vx.end());
  int min_y = *min_element(vy.begin(), vy.end());
  bool ans = false;
  for (int i = x + 1; i <= y; i++) {
    if (max_x < i && min_y >= i) {
      ans = true;
      break;
    }
  }
  
  if (ans) {
    cout << "No War\n";
  } else {
    cout << "War\n"; 
  }
}
