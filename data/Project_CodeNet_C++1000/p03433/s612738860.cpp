#include <bits/stdc++.h>
using namespace std;

int main()
{
  int coins_1yen, price,result;
  cin >>  price >> coins_1yen;
  result=price%500;
  
  if(result <= coins_1yen)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}