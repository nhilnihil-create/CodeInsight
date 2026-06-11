#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool> &checked, vector<vector<int>> &way) {
  checked.at(i) = true;
  for(int j = 0; j < way.at(i).size(); j++) {
    if(checked.at(way.at(i).at(j))) {
      continue;
    }
    dfs(way.at(i).at(j), checked, way);
  }
}
      
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> way(N, vector<int>());
  for(int i = 0; i < M; i++) {
    int a, b, z;
    cin >> a >> b >> z;
    way.at(a - 1).push_back(b - 1);
    way.at(b - 1).push_back(a - 1);
  }
  vector<bool> checked(N, false);
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(checked.at(i)) {
      continue;
    }
    else {
      dfs(i, checked, way);
      count++;
    }
  }
  cout << count << endl;
}