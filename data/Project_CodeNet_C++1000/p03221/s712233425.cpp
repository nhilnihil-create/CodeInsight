#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> V(M);
  vector<vector<int>> Y(N);
  for (int i = 0; i != M; ++i) {
    cin >> V[i].first >> V[i].second;
    Y[V[i].first - 1].push_back(V[i].second);
  }

  for (int i = 0; i != N; ++i) sort(begin(Y[i]), end(Y[i]));

  for (auto &p : V) {
    cout << setfill('0')
         << setw(6) << p.first
         << setw(6)
         << lower_bound(begin(Y[p.first - 1]), end(Y[p.first - 1]), p.second) -
                begin(Y[p.first - 1]) + 1
         << endl;
  }
}
