#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  auto v = vector<vector<int>>(2, vector<int>(N));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> v[i][j];
    }
  }

  int ANS = 0;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += v[0][j];
    }
    for (int j = i; j < N; j++) {
      sum += v[1][j];
    }
    ANS = max(ANS, sum);
  }
  cout << ANS << endl;
}
