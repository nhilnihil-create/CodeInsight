#include <climits>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int answer = INT_MAX;
  for (int i = 1; i < N; ++i) {
    int A = i;
    int B = N - A;
    int sum = 0;
    while (A) {
      sum += A % 10;
      A /= 10;
    }
    while (B) {
      sum += B % 10;
      B /= 10;
    }
    answer = min(answer, sum);
  }
  cout << answer << endl;
  return 0;
}