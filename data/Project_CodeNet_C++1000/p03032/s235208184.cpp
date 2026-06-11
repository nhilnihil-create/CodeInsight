#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K;
  int V[N];
  for (int i = 0; i < N; i++) cin >> V[i];
  int ans = 0;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j + i <= N; j++) {
      int res = 0;
      // i : 左側から取り出す宝石
      // j : 右側から取り出す宝石
      if (i + j > K) {
        continue;
      }
      vector<int> minus;
      for (int k = 0; k < N; k++) {
        if (k < i || k >= N - j) {
          res += V[k];
          if (V[k] < 0) {
            minus.push_back(V[k]);
          }
        }
      }
      sort(minus.begin(),minus.end());
      for (int k = 0; k < min(K - (i + j),(int)minus.size()); k++) {
        res -= minus[k];
      }
      ans = max(ans,res);
    }
  }
  cout << ans << endl;
  return 0;
}