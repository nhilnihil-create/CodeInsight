#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> V(M);
  for (int i = 0; i < M; i++) {
    int P, Y;
    cin >> P >> Y;
    V.at(i) = make_tuple(Y, P, i);
  }
  sort(V.begin(), V.end());
  vector<tuple<int, int, int>> ans(M);
  vector<int> cnt(N + 1);
  for (int i = 0; i < M; i++) {
    cnt.at(get<1>(V.at(i)))++;
    ans.at(i) = make_tuple(get<2>(V.at(i)), get<1>(V.at(i)), cnt.at(get<1>(V.at(i))));
  }
  sort(ans.begin(), ans.end());
  for (auto a : ans) {
    cout << setfill('0') << setw(6) << get<1>(a);
    cout << setfill('0') << setw(6) << get<2>(a);
    cout << "\n";
  }
}