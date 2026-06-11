#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string A, B, C;
  cin >> N >> A >> B >> C;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) == B.at(i) && A.at(i) == C.at(i)) ans += 0;
    else if (A.at(i) == B.at(i) || B.at(i) == C.at(i) || C.at(i) == A.at(i)) ans++;
    else ans += 2;
  }
  cout << ans << endl;
}