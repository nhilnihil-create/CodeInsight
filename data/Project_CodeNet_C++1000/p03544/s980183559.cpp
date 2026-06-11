#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n + 1);
  a.at(0) = 2;
  a.at(1) = 1;
  rep(i, n - 1) a.at(i + 2) = a.at(i + 1) + a.at(i);
  cout << a.at(n) << endl;
}