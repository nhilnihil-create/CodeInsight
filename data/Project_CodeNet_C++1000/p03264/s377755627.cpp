#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  int K, o = 0, e = 0, count = 1;
  cin >> K;
  while (count <= K) {
    e += 1;
    count += 2;
  }
  count = 2;
  while (count <= K) {
    o += 1;
    count += 2;
  }
  cout << e * o << endl;
}
