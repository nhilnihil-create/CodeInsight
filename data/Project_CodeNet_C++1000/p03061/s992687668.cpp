#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long> A(N);
  for (int i =0; i<N; i++) {
    cin >> A.at(i);
  }
  
  vector<long> L(N); // 対象の番号より小さい番号のGCD
  vector<long> R(N); // 対象の番号より大きい番号のGCD
  L.at(0) = 0; L.at(1) = A.at(0);
  R.at(N-1) = 0; R.at(N-2) = A.at(N-1);
  for (int i =2; i<N; i++) {
    L.at(i) = __gcd(L.at(i-1),A.at(i-1));
  }
  for (int i =N-3; i>=0; i--) {
    R.at(i) = __gcd(R.at(i+1),A.at(i+1));
  }
  long ans =0;
  for (int i =0; i<N; i++) {
    ans = max(__gcd(L.at(i),R.at(i)),ans);
  }
  cout << ans << endl;
}