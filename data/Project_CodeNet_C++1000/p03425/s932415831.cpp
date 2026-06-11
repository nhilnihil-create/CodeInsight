#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  int64_t M = 0, A = 0, R = 0, C = 0, H = 0;
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
    if (S.at(i).at(0) =='M') {
      M++;
    }
    if (S.at(i).at(0) =='A') {
      A++;
    }
    if (S.at(i).at(0) =='R') {
      R++;
    }
    if (S.at(i).at(0) =='C') {
      C++;
    }
    if (S.at(i).at(0) =='H') {
      H++;
    }    
  }
  int64_t ans = 0;
  ans += (M * A * R);
  ans += (M * A * C);
  ans += (M * A * H);
  ans += (M * R * C);
  ans += (M * R * H);
  ans += (M * C * H);
  ans += (A * R * C);
  ans += (A * R * H);
  ans += (A * C * H);
  ans += (R * C * H);
  cout << ans << endl;
}