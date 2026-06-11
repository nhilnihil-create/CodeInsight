#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int S;
  if (N % 2) {
    S = N;
  } else {
    S = N + 1;
  }

  vector<vector<bool>> edge(N + 1, vector<bool>(N + 1, false));
  int count = 0;
  for (int i = 1; i <= N - 1; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      if (i == j || (S - i) == j) continue;
      edge[i][j] = true;
      ++count;
    }
  }

  cout << count << endl;
  for (int i = 1; i <= N - 1; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      if (!edge[i][j]) continue;
      cout << i << " " << j << endl;
    }
  }
  return 0;
}