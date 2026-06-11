#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N + 1);
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    A.at(tmp)++;
  }
  
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 0; i < N + 1; i++) {
    if (A.at(i) == 0) {
      continue;
    }
    if (N + 1 - i <= K) {
      cout << ans << endl;
      break;
    } else {
      ans += A.at(i);
    }
  }
}
