#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int s; cin >> s;
  int c = 2;
  vector<int> a;
  a.push_back(s);
  
  while (true) {
    int t = a[c-2];
    if (t % 2 == 0) {
      t /= 2;
    } else {
      t = 3 * t + 1;
    }
    if (find(a.begin(), a.end(), t) != a.end()) {
      cout << c << endl;
      break;
    }
    a.push_back(t);
    c++;
  }
  return 0;
}