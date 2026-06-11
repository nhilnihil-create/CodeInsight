#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a;
  int b;
  int avg;
  double mod;
  
  cin >> a >> b;
  avg = (a + b) / 2;
  mod = (a + b) / 2.0 - avg;
  if(mod > 0)
  {
    avg += 1;
  }
  cout << avg << endl;
}
