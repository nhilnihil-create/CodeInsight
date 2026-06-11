#include <iostream>
#include <stdio.h>

#define MAX_N 100

using namespace std;

int A[MAX_N];

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int j = 1;
    int d = 1;
    while (d <= D) {
      ++cnt;
      d = j++ * A[i] + 1;
    }
  }
  printf("%d\n", cnt + X);
}