#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  vector<int> vec(3);
  rep(i, 3) cin >> vec.at(i);
  sort(vec.begin(), vec.end());
  if (vec.at(0) == vec.at(1)) cout << vec.at(2) << endl;
  else cout << vec.at(0) << endl;
}
