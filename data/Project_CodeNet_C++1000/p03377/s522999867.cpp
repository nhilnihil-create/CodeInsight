#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
int main() {
  int a, b, x;
  cin >> a >> b >> x;
  if (a <= x) {
    if (a+b >= x) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}