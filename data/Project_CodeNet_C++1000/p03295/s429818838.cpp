#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> memo(M, vector<int>(2));
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    memo.at(i).at(1) = a;
    memo.at(i).at(0) = b - 1;
  }
  int c = 0;
  sort(memo.begin(), memo.end());
  int G = 0;
  for (int i = 0; i < M; i++) {
    if (memo.at(i).at(1) > G) {
      c++;
      G = memo.at(i).at(0);
    }
  }
  cout << c << endl;
}