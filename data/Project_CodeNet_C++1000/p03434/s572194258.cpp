#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v.at(i);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int A = 0, B = 0;
  rep(i, n) if (!(i % 2)) A += v.at(i);
  rep(i, n) if ( (i % 2)) B += v.at(i);
  cout << A - B << endl;
}
