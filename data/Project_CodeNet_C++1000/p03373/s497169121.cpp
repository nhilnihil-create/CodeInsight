#include <bits/stdc++.h>
using namespace std;
 
/*int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if (C >= A && C >= B) cout << A*X + B*Y << endl;
  else if (C <= A && C <= B) {
    if (X > Y) {
      if (C*2*Y+A*(X-Y) < C*2*X) cout << C*2*Y+A*(X-Y) << endl;
      else cout << C*2*X;
    } else {
      if (C*2*X+A*(Y-X) < C*2*Y) cout << C*2*X+A*(Y-X) << endl;
      else cout << C*2*Y;
    }
  }
  else {
    int a,x;
    if (A > B) {
      a = A;
      x = X;
      A = B;
      B = a;
      X = Y;
      Y = x;
    }
    int max = 0;
    if (X < Y) {
      for (int i = 0; i <= X; i++) {
        if ((A-C)*i + (B-C)*i > max) max = (A-C)*i + (B-C)*i;
      }
      for (int i = X+1; i <= Y; i++) {
        if ((A-C)*i + (B-C)*i - A*(2*i-X) > max) max = (A-C)*i + (B-C)*i - A*(2*i-X);
      }
    }
    else {
      for (int i = 0; i <= Y; i++) {
        if ((A-C)*i + (B-C)*i > max) max = (A-C)*i + (B-C)*i;
      }
    }
    cout << A*X+B*Y-max << endl;
  }
}*/

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if (X > Y) {
    swap(A, B);
    swap(X, Y);
  }
  int min = 1000000000;
  for (int i = 0; i <= Y; i++) {
    int x = C*2*i + A*max(0, X-i) + B*max(0, Y-i);
    if (x < min) min = x;
  }
  cout << min << endl;
}
