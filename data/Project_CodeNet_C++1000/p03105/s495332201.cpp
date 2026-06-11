#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main() {
  int A, B, C, max_count;
  cin >> A >> B >> C;
  max_count = B / A;
  if (C <= max_count) cout << C << endl;
  else cout << max_count << endl;
}