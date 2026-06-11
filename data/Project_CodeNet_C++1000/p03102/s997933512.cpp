#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, C;
  cin >> N >> M >> C;

  vector<int> B(M);
  for (int i = 0; i < M; ++i) {
    cin >> B.at(i);
  }
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A.at(i).at(j);
    }
  }

  int counter = 0;
  for (int i = 0; i < N; ++i) {
    int sum = C;
    for (int j = 0; j < M; ++j) {
      sum += A.at(i).at(j) * B.at(j);
    }
    if (sum > 0) {
      counter++;
    }
  }
  cout << counter << endl;
}
