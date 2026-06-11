#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  for(int i = 0; i < M; i++){
    cin >> X[i];
  }
  sort(X.begin(), X.end());
  vector<int> dif(M-1); 
  for(int i = 0; i < M-1; i++){
    dif[i] = X[i+1] - X[i];
  }
  sort(dif.begin(), dif.end());
  long long ans = 0;
  for(int i = 0; i < M-N; i++){
    ans += dif[i];
  }
  cout << ans <<endl;
}