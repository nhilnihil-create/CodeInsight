#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
char t[200010], d[200010];

int f(int n) {  // 左に落ちる→-1、落ちない→0、右に落ちる→1
  for (int i = 0; i < q; i++) {
    if (s[n] == t[i]) {
      if (d[i] == 'L') n--;
      if (d[i] == 'R') n++;
    }
    if (n < 0)
      return -1;
    if (s.size() <= n)
      return 1;
  }
  return 0;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  cin >> n >> q;
  cin >> s;
  for (int i = 0; i < q; i++) cin >> t[i] >> d[i];

  // にぶたん
  int left = 0, right = s.size();
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (f(mid) == -1)
      left = mid;
    else
      right = mid;
  }
  int l = right;

  left = 0;
  right = s.size();
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (f(mid) != 1)
      left = mid;
    else
      right = mid;
  }
  int r = right;

  cout << r - l << endl;
}
