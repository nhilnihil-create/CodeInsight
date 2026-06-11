#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int answer = 0;
  for (int i = 1; i * i <= N; ++i) {
    answer = i * i;
  }
  cout << answer << endl;
  return 0;
}