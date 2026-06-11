#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A,B,C;
  cin >> A >> B >> C;

  if (A+B >= C) {
    cout << "Yes" << endl;
  }

  else {
    cout << "No" << endl;
  }
  return 0;
}
