#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N - 1);
  vector<int> C(N - 2);
  cin >> A.at(0);
  int ans = abs(A.at(0));
  for (int i = 1; i < N; i++) {
    cin >> A.at(i);
    B.at(i - 1) = abs(A.at(i) - A.at(i - 1));
    ans += B.at(i - 1);
  }
  ans += abs(A.at(N -1));
  for (int i = 0; i < N - 2; i++) {
    C.at(i) = abs(A.at(i + 2) - A.at(i));
  }
  cout << ans - B.at(0) - abs(A.at(0)) + abs(A.at(1)) << endl;
  for (int i = 1; i < N - 1; i++) {
    int memo = ans;
    memo -= (B.at(i - 1) + B.at(i));
    memo += C.at(i - 1);
    cout << memo << endl;
  }
  cout << ans - B.at(N - 2) - abs(A.at(N - 1)) + abs(A.at(N - 2)) << endl;
}
    