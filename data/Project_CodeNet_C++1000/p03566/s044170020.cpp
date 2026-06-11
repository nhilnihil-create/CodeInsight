#include <bits/stdc++.h>
using namespace std;
int INF = 100;
int main(){
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  vector<int> t(N);
  for (int i = 0; i < N; i++){
    cin >> t[i];
  }
  vector<int> v(N);
  for (int j = 0; j < N; j++){
    cin >> v[j];
  }
  vector<int> S(N + 1, 0);
  for (int i = 0; i < N; i++){
    S[i + 1] = S[i] + t[i] * 2;
  }
  int T = S[N];
  vector<double> V(T + 1, INF);
  for (int i = 0; i < N; i++){
    for (int j = S[i]; j <= S[i + 1]; j++){
      V[j] = min(V[j], (double) v[i]);
    }
  }
  V[0] = 0;
  for (int i = 1; i <= T; i++){
    V[i] = min(V[i], V[i - 1] + 0.5);
  }
  V[T] = 0;
  for (int i = T - 1; i >= 0; i--){
    V[i] = min(V[i], V[i + 1] + 0.5);
  }
  double ans = 0;
  for (int i = 0; i < T; i++){
    ans += V[i] + V[i + 1];
  }
  ans /= 4;
  cout << ans << endl;
}
