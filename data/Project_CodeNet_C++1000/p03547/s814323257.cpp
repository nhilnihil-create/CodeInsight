#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string X, Y;
  cin >> X >> Y;

  if (X > Y)
    cout << '>' << endl;
  else if (X < Y)
    cout << '<' << endl;
  else
    cout << '=' << endl;
  return 0;
}