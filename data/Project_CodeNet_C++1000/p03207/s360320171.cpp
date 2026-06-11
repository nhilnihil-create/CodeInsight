#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  int p[N];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  
  sort(p, p+N, greater<int>());
  
  int ans = p[0]/2;
  
  for (int i = 1; i < N; i++) {
    ans += p[i];
  }
  
  cout << ans << endl;

  return 0;
}