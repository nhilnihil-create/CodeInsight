#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n,a,b;
  cin >> n;
  cin >> a >> b;

  int p[n];
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> p[i];
    if(p[i] <= a)
      num1++;
    else if(p[i] <= b)
      num2++;
    else
      num3++;
  }
  cout << min({num1,num2,num3});
  
  return 0;
}