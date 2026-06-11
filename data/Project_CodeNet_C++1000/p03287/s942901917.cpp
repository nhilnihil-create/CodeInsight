#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<long long> S(N+1);
  S.at(0) = 0;
  for (int i = 0; i < N; i++) S.at(i+1) = (S.at(i) + A.at(i)) % M;
  map<int, int> m;
  long long ans = 0;
  // 自分と同じ数字 (余り) が左に何個あるのか
  for (int i = 0; i <= N; i++) {
    if (m.count(S.at(i))) {
      ans += m[S.at(i)];
      m[S.at(i)]++;
    }
    else m[S.at(i)] = 1;
  }
  cout << ans << endl;
}
