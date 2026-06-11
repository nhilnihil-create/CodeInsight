#include <bits/stdc++.h>
using namespace std;

int fn(int n) {
  if (n % 2 == 0) return n / 2;
  return 3 * n + 1;
}

int main() {
  bool flag = false;
  int s, i, j, count = 0;
  cin >> s;
  vector<int> line = {s};
  while (count != 2) {
    s = fn(s);
    if (s == 1) count++;
    line.push_back(s);
  }
  count = 0;
  for (i = 0; i < line.size(); i++) {
    for (j = i + 1; j < line.size(); j++) {
      if (line[i] == line[j]) {
        flag = true;
        break;
      }
    }
    if (flag) break;
    count++;
  }
  cout << j + 1 << endl;
  return 0;
}