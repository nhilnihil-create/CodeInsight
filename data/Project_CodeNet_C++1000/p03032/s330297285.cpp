#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  rep(i, N) cin >> V[i];
  
  int ans = 0, r, total, t;
  for (int k = 1; k <= min(K, N); k++) {
    t = K - k;  // number of operatation C and D
    for (int l = 0; l <= k; l++) {
      r = k - l;
      vector<int> T;
      for (int i = 0; i < l; i++) T.push_back(V[i]);
      for (int i = N - r; i < N; i++) T.push_back(V[i]);
      sort(T.begin(), T.end());
      rep(i, t) if (T[i] < 0) T[i] = 0;
      total = 0;
      for (int x: T) total += x;
      if (total > ans) ans = total;
    }
  }
  cout << ans << endl;

  return 0;
}
