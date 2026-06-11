#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c, d; cin >> a >> b >> c >> d;
  if (abs(a-c) <= d || abs(a-b) <= d && abs(b-c) <= d)
    cout << "Yes\n";
  else
    cout << "No\n";
}