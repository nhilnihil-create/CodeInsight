#include <bits/stdc++.h>
using namespace std;

bool f(int pos, vector<int>& v) {
  cout << pos << endl;
  string s;
  cin >> s;
  if (s == "Vacant")
    return true;
  if (s == "Male")
    v[pos] = 1;
  if (s == "Female")
    v[pos] = 2;
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n, 0);
  if (f(0, v)) {
    return 0;
  }
  if (f(n - 1, v)) {
    return 0;
  }

  int l = 0, r = n - 1;
  for (int i = 0; i < 20 - 2; ++i) {
    int h = l + (r - l) / 2;
    if (f(h, v)) {
      return 0;
    }

    if ((h - l) % 2 == 0 && v[h] != v[l]) {
      r = h;
    }
    if ((h - l) % 2 != 0 && v[h] == v[l]) {
      r = h;
    }
    if ((r - h) % 2 == 0 && v[r] != v[h]) {
      l = h;
    }
    if ((r - h) % 2 != 0 && v[r] == v[h]) {
      l = h;
    }
  }
}