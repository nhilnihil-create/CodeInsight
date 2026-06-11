#include <bits/stdc++.h>
using namespace std;

int f(int N) {
  int res = 0;
  while (N % 100 == 0) ++res, N /= 100;
  return res;
}

int main() {
  int D, N;
  cin >> D >> N;
  int con = 0, res = 0;
  for (int i = 1; i <= 10000000; ++i) {
    if (f(i) == D) ++con;
    if (con == N) {
      res = i;
      break;
    }
  } 
  cout << res << endl;
}
    