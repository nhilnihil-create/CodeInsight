#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
1
1 0 0 1 0 0 0 0 0 1
3 4 5 6 7 8 9 -2 -3 4 -2
*/

int main() {
  int N;
  cin >> N;

  const int kPeriods = 10;

  vector<int> F(N);
  rep(i, N) {
    int f = 0;

    rep(i, kPeriods) {
      int tmp;
      cin >> tmp;
      f += tmp;
      if (i < kPeriods-1) {
        f <<= 1;
      }
    }

    F[i] = f;
  }

  vector<vector<int>> P(N);
  rep(i, N) {
    P[i].resize(kPeriods+1);
    rep(j, kPeriods+1) {
      cin >> P[i][j];
    }
  }

  bool first = true;
  long long mx;
  for (int i = 1; i < 1<<kPeriods; i++) {
    long long sum = 0;

    rep(j, N) {
      int count = 0;
      rep(k, kPeriods) {
        int tmp = i >> k;
        int tmp2 = F[j] >> k;

        if (tmp % 2 & tmp2 % 2) count++;
      }

      sum += P[j][count];
    }

    if (first || mx < sum) {
      mx = sum;
      first = false;
    }
  }

  cout << mx << endl;

  return 0;
}
