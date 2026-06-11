#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  if (S.at(M-1) == 'A') {
    S.at(M-1) = 'a';
  } else if (S.at(M-1) == 'B') {
    S.at(M-1) = 'b';
  } else {
    S.at(M-1) = 'c';
  }
  cout << S << endl;
}