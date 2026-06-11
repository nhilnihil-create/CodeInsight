#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, M; cin >> N >> M; int64_t ans = 0;
  
  vector<pair<int64_t, int64_t>> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i].first >> vec[i].second;
  
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < N; i++) {
    
    if (vec[i].second < M) {
      ans += vec[i].first * vec[i].second;
      M -= vec[i].second;
    }
    
    else {
      ans += vec[i].first * M;
      break;
    }
    
  }
  
  cout << ans << endl;
  
}