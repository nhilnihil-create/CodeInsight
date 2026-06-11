#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, x; cin >> N >> x;
  
  int ans = 0; int64_t sum = 0; int64_t tmp = x;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) {
    cin >> vec[i];
    sum += vec[i];
  }
  
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < N; i++) {
    tmp -= vec[i];
    if (tmp < 0) break;
    ans++;
  }
  
  if (sum < x) cout << ans - 1 << endl;
  
  else cout << ans << endl;
  
}