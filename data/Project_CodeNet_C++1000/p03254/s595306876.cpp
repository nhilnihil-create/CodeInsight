#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  sort(a.begin(), a.end());
  
  int ans = N - 1;
  
  for (int j = 0; j < N; j++) {
    x -= a.at(j);
    if (x < 0) {
      ans = j;
      break;
    }
    if (x == 0) {
      ans = j + 1;
      break;
    }
  }
  
  cout << ans << endl;
  
}