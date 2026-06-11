#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(M), Y(M);
  vector<vector<int>> yd(N);
  for (int i = 0; i < M; i++) {
    cin >> P.at(i) >> Y.at(i);
    yd.at(P.at(i) - 1).push_back(Y.at(i));
  }
  for (int i = 0; i < N; i++) sort(yd.at(i).begin(), yd.at(i).end());
  for (int i = 0; i < M; i++) {
    string ans1 = to_string(P.at(i));
    while (ans1.size() < 6) ans1 = "0" + ans1;
    string ans2 = to_string(lower_bound(
        yd.at(P.at(i) - 1).begin(), 
        yd.at(P.at(i) - 1).end(), 
        Y.at(i)) 
      - yd.at(P.at(i) - 1).begin() + 1);
    while (ans2.size() < 6) ans2 = "0" + ans2;
    cout << ans1 << ans2 << endl;
  }
}