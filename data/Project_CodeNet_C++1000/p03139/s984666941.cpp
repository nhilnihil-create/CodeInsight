#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if(a+b-n>=0) {
    cout << min(a, b) << ' ' << (a+b)-n << endl;
  }
  else {
    cout << min(a, b) << ' ' << 0 << endl;
  }
}