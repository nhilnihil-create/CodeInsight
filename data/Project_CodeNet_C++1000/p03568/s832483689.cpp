#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  int ans = 1;
  
  rep(i, N) if(A[i]%2 == 0) ans *= 2;
  ans = pow(3, N) - ans;
  cout << ans << endl;
  
}