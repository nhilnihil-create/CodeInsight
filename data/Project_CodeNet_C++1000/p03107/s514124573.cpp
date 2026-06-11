#include <bits/stdc++.h>
using namespace std;


int main()
{
  string A;
  cin >> A;
  int a=0,b=0;
  for(int i=0; i<A.size(); i++)
  {
    if(A.at(i)=='0')
    {
      a++;
    }
    else
    {
      b++;
    }
  }
  cout << A.size()-abs(a-b) << endl;
}