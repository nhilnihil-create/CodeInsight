#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n, y; 
  cin >> n >> y;
  for(int i = 0; i <= n; i++) 
  {
    for(int j = 0; j <= n; j++)
    {
      int k = (y - (10000*i + 5000*j)) / 1000;
      if(i+j+k == n && k >= 0)
      {
        cout << i << " " << j << " "
        << k << endl;
        goto Exit;
      }
    }
  }
  cout << "-1" << " " << "-1" << " "
  << "-1" << endl;
  Exit: ;
  return 0;
}