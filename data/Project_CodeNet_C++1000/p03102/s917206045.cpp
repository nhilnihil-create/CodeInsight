#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  for(int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  int ans = 0;
  for(int i = 0; i < N; i++) {
    vector<int> A(M);
    int sum = 0;
    for(int j = 0; j < M; j++) {
      cin >> A.at(j);
      sum += A.at(j) * B.at(j);
    }
    sum += C;
    if(sum > 0) {
      ans++;
    }
  }
  cout << ans << endl;
}