#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  //  6   3   1   2   7   4   8   5
  // [1] [2] [3] [4] [5] [6] [7] [8]
  //
  //  1   2   3   4   5   6   7   8
  // [2] [3] [1] [5] [7] [0] [4] [6]
  for (int i = 0; i < N; i++) {
    int a; cin >> a; a--;
    A.at(a) = i;
  }
  int cnt = 0;
  int tmp = 1;
  for (int i = 1; i < N; i++) {
    if (A.at(i) > A.at(i-1)) tmp++;
    else {
      cnt = max(cnt, tmp);
      tmp = 1;
    }
  }
  cnt = max(cnt, tmp);
  cout << N - cnt << endl;
}