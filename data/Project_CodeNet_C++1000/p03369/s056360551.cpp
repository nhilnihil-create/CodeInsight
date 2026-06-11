#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int m=700;
  string S;
  cin >> S;
  for (char c:S) {
    if (c=='o') {
      m+=100;
    }
  }
  cout << m << endl;
}
