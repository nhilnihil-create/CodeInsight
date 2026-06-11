#include <bits/stdc++.h>
using namespace std;
long long INF = 4000000000000000000;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++){
    cin >> x[i] >> y[i];
  }
  long long ans = INF;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      vector<int> y2;
      for (int k = 0; k < N; k++){
        if (x[i] <= x[k] && x[k] <= x[j]){
          y2.push_back(y[k]);
        }
      }
      sort(y2.begin(), y2.end());
      if (y2.size() >= K){
        long long W = abs(x[j] - x[i]);
        int cnt = y2.size();
        for (int i = 0; i < cnt - K + 1; i++){
          long long H = y2[i + K - 1] - y2[i];
          ans = min(ans, H * W);
        }
      }
    }
  }
  cout << ans << endl;
}