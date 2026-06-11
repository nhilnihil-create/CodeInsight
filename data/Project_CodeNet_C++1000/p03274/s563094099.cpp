#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  for(int i = 0; i < N; i++){
    cin >> x[i];
  }
  int ans = 999999999;
  for(int i = 0; i < N - K + 1; i++){
    int dif = abs(x[i] - x[i+K-1]);
    int tmp = min(abs(x[i]) + dif, abs(x[i+K-1]) + dif);
    if(ans > tmp){
      ans = tmp;
    }
  }
  cout << ans <<endl;
}
