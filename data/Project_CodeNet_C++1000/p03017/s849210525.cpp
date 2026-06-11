#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C, D;
  string S;
  cin >> N >> A >> B >> C >> D >> S, A--, B--, C--, D--;
  auto f = [&](int l, int r, string T) {
    return ((int) S.substr(l, r - l + 1).find(T) != -1) ? true : false;
  };
  if (f(A, C, "##") || f(B, D, "##") || (D < C && !f(B - 1, D + 1, "..."))) cout << "No" << "\n";
  else cout << "Yes" << "\n";
}