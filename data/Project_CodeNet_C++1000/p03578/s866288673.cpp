#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  map<int, int> dmp;
  int D;
  rep(i, N) {
    cin >> D;
    dmp[D]++;
  }

  int M;
  cin >> M;
  map<int, int> tmp;
  int T;
  rep(i, M) {
    cin >> T;
    tmp[T]++;
  }

  for (auto x : tmp) {
    if (x.second > dmp[x.first]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}