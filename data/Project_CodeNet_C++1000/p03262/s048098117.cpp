#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; int64_t X; cin >> N >> X;
  
  if (N == 1) {
    int64_t x; cin >> x;
    cout << abs(X - x) << endl;
    return 0;
  }
  
  vector<int64_t> vec(N), dif(N - 1);
  
  for (int i = 0; i < N; i++) {
    int64_t x; cin >> x;
    x = abs(x - X);
    vec[i] = x;
  }
  
  int64_t ans = vec[0];
  
  for (int i = 0; i < N - 1; i++) {
    ans = __gcd(ans, abs(vec[i + 1] - vec[i]));
  }
  
  cout << ans << endl;
  
}