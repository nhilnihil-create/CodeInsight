#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 DigitSum(int64 x) {
  string s = to_string(x);
  int64 sum = 0;
  for (char c : s) {
    sum += c - '0';
  }
  return sum;
}

int64 NextSnuke(int64 x) {
  int64 min_arg = x;
  int64 min_num = x;
  int64 min_den = DigitSum(x);

  string s = to_string(x);
  for (int i = 0; i < s.length(); i++) {
    for (char d = '0'; d <= '9'; d++) {
      string t = s;
      t[i] = d;
      for (int j = i + 1; j < s.length(); j++) {
        t[j] = '9';
      }
      int64 y = stoll(t);
      if (y < x) continue;

      int64 num = y;
      int64 den = DigitSum(y);
      if (num * min_den < min_num * den) {
        min_arg = y;
        min_num = num;
        min_den = den;
      } else if (num * min_den == min_num * den && y < min_arg) {
        min_arg = y;
      }
    }
  }

  return min_arg;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;
  int64 current = 1;
  for (int i = 0; i < k; i++) {
    int64 x = NextSnuke(current);
    cout << x << endl;
    current = x + 1;
  }
}