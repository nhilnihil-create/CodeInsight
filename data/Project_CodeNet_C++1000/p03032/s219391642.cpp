#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  for (int i = 0; i < N; i++){
    cin >> V[i];
  }
  int ans = -INF;
  for (int i = 0; i <= N; i++){
    for (int j = 0; j <= N - i; j++){
      if (i + j <= K){
        vector<int> A;
        for (int k = 0; k < i; k++){
          A.push_back(V[k]);
        }
        for (int k = 0; k < j; k++){
          A.push_back(V[N - 1 - k]);
        }
        sort(A.begin(), A.end());
        int C = K - (i + j);
        int sum = 0;
        for (int k = 0; k < i + j; k++){
          if (k < C){
            sum += max(A[k], 0);
          } else {
            sum += A[k];
          }
        }
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
}