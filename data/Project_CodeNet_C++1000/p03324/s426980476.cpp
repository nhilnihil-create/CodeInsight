#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (m != 100) {
  if (n != 0) {
    cout << pow(100, n)*m << endl;
  }
  if (n == 0) {
    cout << 1*m << endl;
  }
  }
  else {
    if (n != 0) {
      if (n == 2) {
        cout << 1010000 << endl;
      }
      else {
    cout << pow(100, n)*101 << endl;
  }
    }
  if (n == 0) {
    cout << 1*101 << endl;
  }
  }
}