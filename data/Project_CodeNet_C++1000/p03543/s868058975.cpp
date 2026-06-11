#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, result1000 , result100 , result10 ,result1;
  cin >>  A;
  result1000 = A/1000;
  result100 = (A-result1000*1000)/100;
  result10 = (A-result1000*1000-result100*100)/10;
  result1 = A-result1000*1000-result100*100-result10*10;
  if(((result1000 == result100) && (result100 == result10)) || ((result100 == result10) && (result10 == result1)))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}