#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int a,b;
  cin >> a >> b;
  if (a * b == 15) {
    cout << "*" << endl;
  } else if (a + b == 15) {
    cout << "+" << endl;
  } else {
    cout << "x" << endl;
  }
  return 0;
}
