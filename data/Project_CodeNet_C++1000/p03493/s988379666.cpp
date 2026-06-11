#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  cout << s / 100 + (s / 10  - (s / 100) * 10) + (s - (s / 100) * 100 - (s / 10  - (s / 100) * 10) * 10) << endl;
}
