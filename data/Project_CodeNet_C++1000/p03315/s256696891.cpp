#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int plus_count = count(s.begin(), s.end(), '+');
  int minus_count = count(s.begin(), s.end(), '-');
  cout << plus_count - minus_count << endl;
}
