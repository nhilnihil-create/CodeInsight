#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  int answer = 1;
  for (int i = 0; i < N; ++i) {
    int next0 = answer * 2;
    int next1 = answer + K;
    answer = min(next0, next1);
  }
  cout << answer << endl;
  return 0;
}