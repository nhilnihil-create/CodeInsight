#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c;
  cin >> a>>b>>c;
  int x = b/a;
  if(x > c)
  {
    x = c;
  }
  cout << x<<endl;
}