#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int i,n,big=0,small=0;
  cin >> n;
  vector<int> number(n);
  for(i=0;i<n;i++)
  {
    cin >> number.at(i);
  }
  sort(number.begin(), number.end());
  for(i=0;i<n;i++)
  {
    if(i % 2 == 0)
    {
  	 big += number.at(n-i-1);
    }
    else
    {
  	 small += number.at(n-i-1);
    }
  }
  cout << big - small;
  
  return 0;
}