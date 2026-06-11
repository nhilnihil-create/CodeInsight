#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string NS;
  cin >> NS;
  int N = NS.size();
  int answer0 = NS[0] - '0';
  int answer1 = answer0 - 1;
  for (int i = 1; i < N; ++i) {
    answer0 += NS[i] - '0';
    answer1 += 9;
  }
  cout << max(answer0, answer1) << endl;
  return 0;
}
