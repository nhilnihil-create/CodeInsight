#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s;
  bool cont = true;
  while(cont) {
    if (N >= 0) {
      int a = N % (- 2);
      string b = to_string(a);
      s = b + s;
      N /= -2;
    }
    else {
      int a = - (N % (- 2));
      string b = to_string(a);
      s = b + s;
      N = (N - a) / (- 2);
    }
    if (N == 0) {
      cont = false;
    }
  }
  cout << s << endl;
}
