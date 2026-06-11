#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  string key[16];
  string consist[] = {"KIH", "B", "R"};
  for (int i = 0; i < 1 << 4; i ++) {
    int i_ = i;
    string kj = "";
    for (int j = 0; j < 4; j ++) {
      if (i_ % 2) kj += "A";
      i_ /= 2;
      if (j < 3) kj += consist[j];
    }
    key[i] = kj;
  }
  for (int i = 0; i < 16; i ++) {
    if (S == key[i]) {
      cout << "YES" << endl;
      return 0;
    }
    //cout << key[i] << endl;
  }
  cout << "NO" << endl;
}
