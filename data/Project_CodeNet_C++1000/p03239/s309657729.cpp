#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}

int main() {
  int N, T;
  cin >> N >> T;
  
  int ans = 1010;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    
    if (t <= T) {
      chmin(ans, c);
    }
  }
  
  if (ans == 1010) {
    cout << "TLE" << endl;
  } else {
    cout << ans << endl;
  }
  
}