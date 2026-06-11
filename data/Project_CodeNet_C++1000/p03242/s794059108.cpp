#include<bits/stdc++.h>
using namespace std;
int main()
{
  string A;
  cin >> A;
  for(int i=0; i<3 ; i++)
  {
    if(A.at(i)=='9')cout << '1';
    if(A.at(i)=='1')cout << '9';
  }
  cout << endl;
}