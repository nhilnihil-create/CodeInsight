#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int res = 0;
  for (int i = 1; i <= N; i += 2) {
    int con = 0;
    for (int j = 1; j <= i; ++j) {
      if (i % j == 0) ++con;
    }
    if (con == 8) ++res;
  }
  cout << res << endl;
}