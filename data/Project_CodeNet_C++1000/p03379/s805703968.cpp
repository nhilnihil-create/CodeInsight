#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;

  vector<int> X(N);
  rep(i, N) cin >> X[i];

  vector<int> S = X;
  std::sort(S.begin(), S.end());

  std::map<int, int> pos;
  rep(i, N) {
    pos[S[i]] = i;
  }

  rep(i, N) {
    int num = X[i];

    if (pos[X[i]] < N / 2) cout << S[N / 2] << endl;
    else cout << S[N / 2 - 1] << endl;
  }

  return 0;
}
