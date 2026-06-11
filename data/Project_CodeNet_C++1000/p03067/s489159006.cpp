#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) {
    swap(a, b);
  }

  if (a <= c && c <= b) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}