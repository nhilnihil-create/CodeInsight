#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<long long> S(N + 1, 0);
  for (int i = 0; i < N; i++){
    S[i + 1] = S[i] + a[i];
  }
  vector<long long> sum;
  for (int i = 0; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      sum.push_back(S[j] - S[i]);
    }
  }
  long long ans = 0;
  for (int i = 50; i >= 0; i--){
    int cnt = 0;
    int M = sum.size();
    for (int j = 0; j < M; j++){
      if (sum[j] >> i & 1){
        cnt++;
      }
    }
    if (cnt >= K){
      ans += (long long) 1 << i;
      vector<long long> sum2;
      for (int j = 0; j < M; j++){
        if (sum[j] >> i & 1){
          sum2.push_back(sum[j]);
        }
      }
      swap(sum, sum2);
    }
  }
  cout << ans << endl;
}