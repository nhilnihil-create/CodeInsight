#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, t;
  cin >> a >> b >> t;
  int x = (t + 0.5) / a;
  // i * a <= t + 0.5
  // i <= (t + 0.5) / a
  int bis = b * x;
  
  cout << bis << endl;
}
