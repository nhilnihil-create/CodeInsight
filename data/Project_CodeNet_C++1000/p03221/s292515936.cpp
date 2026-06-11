#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> p(M);
  for (int i = 0; i < M; i++) {
    int P, Y;
    cin >> P >> Y;
    P--;
    p.at(i) = make_pair(Y, P);
  }

  vector<vector<int>> vals(N);
  for (int i = 0; i < M; i++) vals.at(p.at(i).second).push_back(p.at(i).first);

  for (int v = 0; v < N; v++) {
    sort(vals.at(v).begin(), vals.at(v).end());
  }

  for (int i = 0; i < M; ++i) {
    int v = p.at(i).second;
    printf("%06d", v + 1);
    int id = lower_bound(vals.at(v).begin(), vals.at(v).end(), p.at(i).first) -
             vals.at(v).begin();
    printf("%06d\n", id + 1);
  }
}