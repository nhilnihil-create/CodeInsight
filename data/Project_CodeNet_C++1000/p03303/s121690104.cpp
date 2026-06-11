#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int W;
  cin >> S >> W;
  int N = S.size();
  for (int i = 0; i < N;) {
    cout << S.at(i);
    i += W;
  }
  cout << "\n";
}