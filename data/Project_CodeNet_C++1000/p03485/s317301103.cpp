#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,x;
  cin >> a >> b;
  if((a + b) % 2 == 0)
    x = (a + b)/2;
  else 
    x = (a + b) / 2 + 1;
    
  cout << x << endl;
}