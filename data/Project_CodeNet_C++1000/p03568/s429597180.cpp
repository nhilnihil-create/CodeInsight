#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int answer = 1;
  int odd_pattern = 1;
  rep(i, N) {
    int a;
    cin >> a;
    if (a % 2 == 0) {
      odd_pattern *= 2;
    } else {
      odd_pattern *= 1;
    }
    answer *= 3;
  }
  answer -= odd_pattern;
  cout << answer << endl;
  return 0;
}
