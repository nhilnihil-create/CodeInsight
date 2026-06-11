#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, t=0;
  cin >> s;
  while (s>0) {
    t+=s%10;
    s/=10;
  }
  cout << t << endl;
}
