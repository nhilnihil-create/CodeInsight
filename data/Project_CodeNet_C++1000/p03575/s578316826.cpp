#include <bits/stdc++.h>
using namespace std;

void dfs(int x, const vector<vector<bool>>& bridges, vector<bool>& visits) {
  if (visits.at(x)) {
    return;
  }
  visits.at(x) = true;
  for (int i = 0; i < bridges.at(x).size(); i++) {
    if (bridges.at(x).at(i)) {
      dfs(i, bridges, visits);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> bridges(N, vector<bool>(N, false));
  vector<pair<int, int>> sides(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    sides.at(i).first = a;
    sides.at(i).second = b;
    bridges.at(a).at(b) = true;
    bridges.at(b).at(a) = true;
  }
  int count = 0;
  for (int i = 0; i < M; i++) {
    bridges.at(sides.at(i).first).at(sides.at(i).second) = false;
    bridges.at(sides.at(i).second).at(sides.at(i).first) = false;

    vector<bool> visits(N, false);
    dfs(0, bridges, visits);
    for (int iv = 0; iv < N; iv++) {
      if (visits.at(iv) == false) {
        count++;
        break;
      }
    }
    bridges.at(sides.at(i).first).at(sides.at(i).second) = true;
    bridges.at(sides.at(i).second).at(sides.at(i).first) = true;
  }
  cout << count << endl;
}