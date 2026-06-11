#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  int X = A.size();
  rep2(i, X - 8, X) {
    A.at(i) = ' ';
  }
  cout << A << endl;
}
