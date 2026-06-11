#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, A[100][100];

int main(int argc, char* argv[]) {
  cin >> N;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  int score = A[0][0];
  for (int i = 0; i < N; i++)
    score += A[1][i];
  int res = score;

  for (int i = 1; i < N; i++) {
    score += A[0][i] - A[1][i - 1];
    if (res < score)
      res = score;
  }

  cout << res << endl;

  return 0;
}
