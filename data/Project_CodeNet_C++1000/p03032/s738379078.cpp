#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int INF = -1e9-100;

signed main(){
  int N, K; cin >> N >> K;
  vector<int> A(N);
  int ans = INF;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int a = 0; a <= K; a++){
    for(int b = 0; b <= K; b++){
      if(a + b > min(N, K)) continue;
      vector<int> data;
      int ans1 = 0;
      for(int i = 0; i < a; i++) ans1 += A[i], data.push_back(A[i]);
      for(int i = N - 1; i > N - 1 - b; i--) ans1 += A[i], data.push_back(A[i]);
      sort(data.begin(), data.end());
      for(int i = 0; i < min(K - a - b, a + b); i++) if(data[i] < 0) ans1 -= data[i];
      ans = max(ans, ans1);
    }
  }
  cout << ans << endl;
}
