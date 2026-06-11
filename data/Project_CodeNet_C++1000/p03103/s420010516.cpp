#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int64_t N, M;
  cin >> N >> M;
  vector<vector<int64_t>> A(N, vector<int64_t>(2));
  for (int64_t i = 0; i < N; i++) {
    cin >> A.at(i).at(0) >> A.at(i).at(1);
  }
  sort (A.begin(), A.end());
  int64_t memo = 0;
  int64_t ans = 0;
  for (int64_t i = 0; i < N; i++) {  
    if (memo == M) {
      break;
    }
    if (M - memo >= A.at(i).at(1)) {
      ans += (A.at(i).at(0) * A.at(i).at(1));
      memo += A.at(i).at(1);
    }
    else {
      ans += (A.at(i).at(0) * (M - memo));
      memo = M;
    }
  }
  cout << ans << endl;
}