#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  int c,d;
  cin >> a >> b >> c >> d;
  int n = a + b;
  int m = c + d;
  if(n == m)
  {
    cout << "Balanced" << endl;
  }
  else if(n > m)
  {
    cout << "Left" << endl;
  }
  else if(n < m)
  {
    cout << "Right" << endl;
  }
}
