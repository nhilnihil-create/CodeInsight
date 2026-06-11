#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, T, A;
  cin >> N >> T >> A;
  int H[N];
  for(int i=0; i<N; ++i) cin >> H[i];
  int ans, n;
  int d = 1e9;
  for(int i=0; i<N; ++i){
    n = abs(1000*A-(1000*T-H[i]*6));
    if (d > n){
      ans = i+1;
      d = n;
    }
  }
  cout << ans << endl;
}