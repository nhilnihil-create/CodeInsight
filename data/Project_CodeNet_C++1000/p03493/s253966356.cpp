#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  int t = s / 100;
  int u = (s - t * 100) / 10;
  int w = s - t * 100 - u *10;
  cout << t + u + w << endl;
}
