#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, C;
  int count = 0;
  cin >> N >> M >> C;
  vector<vector<int>> data(1+N, vector<int>(M));
  for (int i = 0; i < 1+N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> data.at(i).at(j);
    }
  }

  for (int i = 1; i < 1+N; i++) {
    int sum = 0;
    for (int j = 0; j < M; j++) {
      sum += data.at(i).at(j) * data.at(0).at(j);
    }
    if (sum + C > 0) count++;
  }

  cout << count << endl;
}