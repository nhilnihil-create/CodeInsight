#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, ret = 0;
  cin >> s;
  
  ret += s / 100;
  s -= s / 100 * 100;
  ret += s / 10;
  s -= s / 10 * 10;
  ret += s / 1;
  
  cout << ret << endl;
}
