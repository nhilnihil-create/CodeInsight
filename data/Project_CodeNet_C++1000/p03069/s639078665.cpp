#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, fl = 0;
  string s, as;
  cin >> N >> s;
  for (int i = 0; i < N; i++) {
    as += '#';
    if (s[i] == '.') fl += 1;
  }
  int m = fl;
  for (int i = 0; i < N; i++) {
    as[i] = '.';
    if (s[i] == '.') fl -= 1;
    else fl += 1;
    m = min(m,fl);
  }
  cout << m << endl;
}