#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a; cin >> a;
  int b; cin >> b;
  if (a <= 5)
  {
    cout << 0 << endl;
  }
  else if (a <= 12)
  {
    cout << b / 2 << endl;
  }
  else
  {
    cout << b << endl;
  }
  
}