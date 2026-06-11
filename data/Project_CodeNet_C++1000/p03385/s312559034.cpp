#include <bits/stdc++.h>
using namespace std;

int main() {
  char d, e, f;
  cin >> d >> e >> f;
  vector<char> T = {d, e, f};
  vector<char> U = {'a', 'b', 'c'};
  sort(T.begin(), T.end());
  if (T == U) cout << "Yes" << endl;
  else cout << "No" << endl;
}