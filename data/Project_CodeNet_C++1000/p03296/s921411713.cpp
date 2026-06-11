#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int prev = 0;
  int answer = 0;
  rep(i, N) {
    int A;
    cin >> A;
    if (prev == A) {
      ++answer;
      A = 0;
    }
    prev = A;
  }
  cout << answer << endl;
  return 0;
}