#include <bits/stdc++.h>
using namespace std;

int main(void) {
  vector<char> N(4);
  for (int i = 0; i < 4; i++) {
    cin >> N[i];
  }
  bool flag = true;
  flag &= find(N.begin(), N.end(), '1') != N.end();
  flag &= find(N.begin(), N.end(), '9') != N.end();
  flag &= find(N.begin(), N.end(), '7') != N.end();
  flag &= find(N.begin(), N.end(), '4') != N.end();
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}