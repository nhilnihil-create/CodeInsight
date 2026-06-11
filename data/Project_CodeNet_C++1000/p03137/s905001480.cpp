#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  if (N >= M) {
    cout << 0 << endl;
  }
  else {
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
      cin >> X.at(i);
    }
    sort(X.begin(), X.end());
    vector<int> memo(M - 1);
    for (int i = 1; i < M; i++) {
      memo.at(i - 1) = X.at(i) - X.at(i - 1);
    }
    sort(memo.begin(), memo.end());   
    int ans = 0;
    for (int i = 0; i < M - N; i++) {
      ans += memo.at(i);
    }
    cout << ans << endl;
  }
}