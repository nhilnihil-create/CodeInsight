#include <iostream>
#include <vector>
using namespace std;

int F[100][10];
int P[100][11];

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }
  int max = -10000000000;
  for (int i = 1; i < (1<<10); i++) {
    int sum = 0;
    for (int k = 0; k < N; k++) {
      int c = 0;
      for (int j = 0; j < 10; j++) {
        if ((i & (1<<j)) && F[k][j]) c++; 
      }
      sum += P[k][c];
    }
    max = max > sum ? max : sum;
  }
  cout << max << endl;
  return 0;
}