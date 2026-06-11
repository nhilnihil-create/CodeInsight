#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LLMAX 9223372036854775807

int sign(int i) {
  return i % 2 == 1 ? 1 : -1;
}

int main() {
  int N, M;
  
  cin >> N >> M;
  
  vector<vector<ll>> sums(8, vector<ll>(N, 0));
  
  for (int i = 0; i < N; i++) {
    ll x, y, z;
    
    cin >> x >> y >> z;
    
    for (int j = 0; j < (1 << 3); j++) {
      int a = (j & 1);
      int b = ((j >> 1) & 1);
      int c = ((j >> 2) & 1);
      
      sums[j][i] = x * sign(a) + y * sign(b) + z * sign(c);
    }
  }
  
  for (int i = 0; i < 8; i++) {
    sort(sums[i].begin(), sums[i].end());
  }
  
  ll ans = -LLMAX;
  
  for (int j = 0; j < (1 << 3); j++) {
    ll sum = 0;
    
    for (int i = 1; i <= M; i++) {
      sum += sums[j][N - i];
    }
    
    ans = max(ans, sum);
  }
  
  cout << ans << endl;
  
  return 0;
}