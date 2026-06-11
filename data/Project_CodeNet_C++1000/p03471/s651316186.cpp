#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, y;
  cin >> n >> y;
  int A, B, C, x, t = 0;
  for(int a = 0;a <= n;a++) {
    for(int b = 0;a + b <= n;b++) {
      int c = n - a - b;
      int t = (10000*a)+(5000*b)+(1000*c);
      if(t == y) {
        A = a;
        B = b;
        C = c;
        x++;
        break;
      }
    }
  }
  if(x != 0) {
  	cout << A << " " << B << " " << C << endl;
  } else {
    cout << -1 << " " << -1 << " " << -1 << endl;
  }
}
