#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> va(3);
  cin >> va[0] >> va[1] >> va[2];
  sort(va.begin(), va.end(), greater<int>());
  cout << va[0] * 10 + va[1] + va[2] << '\n';
}
