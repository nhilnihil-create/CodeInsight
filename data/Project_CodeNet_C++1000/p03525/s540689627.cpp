#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int minTime(vector<int> &arr) {
  int time = 24;
  vector<int> c;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] >= 1) c.push_back(i);
  }
  for (int i = 0; i < c.size() - 1; i++) time = min(time, c[i + 1] - c[i]);
  time = min(time, 24 - c.back());
  return time;
}

int main() {
  int N;
  cin >> N;

  vector<int> D(N);
  for (int i = 0; i < N; i++) cin >> D[i];

  map<int, int> M;
  for (int i = 0; i < N; i++) {
    if (D[i] >= 13) D[i] = 24 - D[i];
    M[D[i]]++;
  }


  for (auto x : M) {
    if ((x.first == 0 && x.second >= 1) || (x.first == 12 && x.second >= 2) ||
        (x.first != 0 && x.first != 12 && x.second >= 3)) {
      cout << 0 << endl;
      return 0;
    }
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << 11); bit++) {
    vector<int> time(24, 0);
    time[0] = 1;
    if (M.count(12)) time[12] = 1;
    bool good = true;
    for (int i = 0; i < 11; i++) {
      //置いてあげる
      if (bit & (1 << i)) {
        if (M[(i + 1)] == 2) {
          time[(i + 1)] = 1;
          time[(24 - (i + 1))] = 1;
        }
        if (M[(i + 1)] == 1) {
          time[(i + 1)] = 1;
        }
      } else {
        if (M[(i + 1)] == 2) {
          good = false;
        }
        if (M[(i + 1)] == 1) {
          time[24 - (i + 1)] = 1;
        }
      }
    }
    if (!good) continue;
    int t = minTime(time);
    ans = max(ans, t);
  }

  cout << ans << endl;
}