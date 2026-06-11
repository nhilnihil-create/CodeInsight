#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

constexpr int SIZE = 35;

template<typename T>
void PrintVector(const vector<T>& xs) {
  for (int i = 0; i < xs.size(); i++) {
    if (i > 0) cout << " ";
    cout << xs[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  bool is_even = false;
  bool is_odd = false;
  vector<int64> xs;
  vector<int64> ys;
  for (int i = 0; i < n; i++) {
    int64 x, y;
    cin >> x >> y;
    xs.push_back(x);
    ys.push_back(y);
    if ((x + y) % 2 == 0) is_even = true;
    else is_odd = true;
  }
  if (is_even && is_odd) {
    cout << -1 << endl;
    return 0;
  }

  vector<int64> ls;
  for (int i = SIZE - 1; i >= 0; i--) {
    ls.push_back(1LL << i);
  }
  if (is_even) {
    ls.push_back(1);
  }
  cout << ls.size() << endl;
  PrintVector(ls);
  cout << endl;

  for (int q = 0; q < n; q++) {
    int64 cur_x = -xs[q];
    int64 cur_y = -ys[q];
    string answer;
    for (int i = 0; i < ls.size(); i++) {
      if (abs(cur_x) >= abs(cur_y)) {
        if (cur_x >= 0) {
          answer.push_back('L');
          cur_x -= ls[i];
        } else {
          answer.push_back('R');
          cur_x += ls[i];
        }
      } else {
        if (cur_y >= 0) {
          answer.push_back('D');
          cur_y -= ls[i];
        } else {
          answer.push_back('U');
          cur_y += ls[i];
        }
      }
    }
    if (cur_x != 0 || cur_y != 0) {
      cerr << "Unexpected!" << endl;
      return 1;
    }
    cout << answer << endl;
  }
}
