#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--, B--, C--, D--;
  string S;
  cin >> S;

  bool flag = true;
  for (int i = A; i < C; i++) {
    if (S.at(i) == '#' && S.at(i + 1) == '#') {
      flag = false;
    }
  }

  for (int i = B; i < D; i++) {
    if (S.at(i) == '#' && S.at(i + 1) == '#') {
      flag = false;
    }
  }

  if (C > D) {
    flag = false;
    for (int i = B; i < D + 1; i++) {
      if (S.at(i - 1) == '.' && S.at(i) == '.' && S.at(i + 1) == '.')
        flag = true;
    }
  }

  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
