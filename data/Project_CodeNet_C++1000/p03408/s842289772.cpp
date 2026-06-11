#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  vector<string> x(a);
  for (int i = 0; i < a; i++) {
    cin >> x[i];
  }
  cin >> b;
  vector<string> y(b);
  for (int i = 0; i < b; i++) {
    cin >> y[i];
  }
  int count = 0;
  vector<int> c(a);
  if (a>b) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (x[i] == x[j]) {
        count++;
      }
      if (j < y.size()) {
      if (x[i] == y[j]) {
        count--;
      }
      }
      if (j == a-1) {
        c[i] = count;
        count = 0;
      }
    }
  }
  }
  else {
    for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (x[i] == y[j]) {
        count--;
      }
      if (j < x.size()) {
      if (x[i] == x[j]) {
        count++;
      }
      }
      if (j == b-1) {
        c[i] = count;
        count = 0;
      }
    }
  }
  }
  sort(c.begin(), c.end());
  if (c[c.size()-1] < 0) {
    cout << 0 << endl;
  }
  else {
  cout << c[c.size()-1] << endl;
  }
}