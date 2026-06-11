#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,M;
  cin >> N >> M;
  vector<pair<int,int> > C;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    C.push_back({A,B});
  }
  sort(C.begin(), C.end());
  int i = 0;
  int64_t ans = 0;
  while (M && i < N) {
    if (C[i].second == 0) {
      i++;
    }
    else {
      ans += C[i].first;
      C[i].second--;
      M--;
    }
  }
  cout << ans << endl;
  return 0;
}