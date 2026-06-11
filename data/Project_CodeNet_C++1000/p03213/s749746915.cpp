#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

map<int, int> count;
int getCount(int n) {
  int ret = 0;
  for (auto& i : count) {
    if (i.second >= n) ++ret;
  }
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  rep(i, N) {
    int n = i + 1;
    for (int64_t j = 2; j * j <= n; ++j) {
      while (n % j == 0) {
        count[j]++;
        n /= j;
      }
    }
    if (n != 1) count[n]++;
  }

  int answer = 0;
  answer += getCount(75 - 1);
  answer += getCount(25 - 1) * (getCount(3 - 1) - 1);
  answer += getCount(15 - 1) * (getCount(5 - 1) - 1);
  answer += getCount(5 - 1) * (getCount(5 - 1) - 1) / 2 * (getCount(3 - 1) - 2);
  cout << answer << endl;
  return 0;
}
