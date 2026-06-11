#include<bits/stdc++.h>
using namespace std;

int main()
{
  int val, val_1000, val_100, val_10;
  cin >> val;
  val_1000 = val / 1000;
  val      = val % 1000;
  
  val_100  = val / 100;
  val      = val % 100;
  
  val_10   = val / 10;
  val      = val % 10;
  
  if ((val_1000 == val_100 && val_100 == val_10) ||(val_100 == val_10 && val_10 == val))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}