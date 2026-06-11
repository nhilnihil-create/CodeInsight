#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;

  int len = N.size();
  int E = len - 7;

  for (int i = 0; i < len; i++) {
    string Ni = N;
    Ni.erase(i, E);
    if (Ni == "keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}