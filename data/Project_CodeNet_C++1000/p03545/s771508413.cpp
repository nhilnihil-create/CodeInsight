#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    a[i] = s[i]-'0';
  }
  for (int bit = 0; bit < (1 << 3); bit++) {
    int sum = a[0];
    for (int i =0; i < 3; i++) {
      if ((1<<i)&bit) {
        sum += a[i+1];
      }
      else {
        sum -= a[i+1];
      }
    }
    if (sum == 7) {
      cout << a[0];
      for (int i =0; i < 3; i++) {
        if ((1<<i)&bit) {
          cout << '+' << a[i+1];
        }
        else {
          cout << '-' << a[i+1];
        }
      }
      cout << '=' << 7 << endl;
      return 0;
    }
  }
}