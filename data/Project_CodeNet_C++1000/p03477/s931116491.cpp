#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int A = a + b, B = c + d;
  if (A > B)
    cout << "Left" << endl;
  else if (A == B)
    cout << "Balanced" << endl;
  else
    cout << "Right" << endl;
}