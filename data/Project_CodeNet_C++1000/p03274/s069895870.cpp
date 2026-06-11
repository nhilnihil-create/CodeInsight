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
    int l = abs(x[i]);
    int r = abs(x[i+K-1]);
    if(x[i] <= 0 && x[i+K-1] <= 0){
      if(ans > l){
        ans = l;
      }
    } else if(x[i] <= 0 && x[i+K-1] >= 0){
      if(ans > min(l*2+r, l+r*2)){
        ans = min(l*2+r, l+r*2);
      }
    } else if(x[i] >= 0 && x[i+K-1] >= 0){
      if(ans > r){
        ans = r;
      }
    }
  }
  cout << ans <<endl;
}
