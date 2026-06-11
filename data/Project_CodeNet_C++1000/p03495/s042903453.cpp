#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> c(N+1, 0);
  int a;
  rep(i, N) {
    cin >> a;
    c[a]++;
  }

  vector<int> balls;
  rep(i, c.size()) {
    if (c[i] > 0) balls.push_back(c[i]);
  }

  std::sort(balls.begin(), balls.end());

  int sum = 0;
  int loop = balls.size() - K;
  rep(i, loop) {
    sum += balls[i];
  }

  cout << sum << endl;

  return 0;
}
