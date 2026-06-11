#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int a;
  	cin >> a;
  
  int count = 0;
  if( a / 100 == 1)
  {
    count++;
  }
  if (a % 100 / 10 == 1)
  {
    count++;
  }
  if (a % 10 == 1)
  {
    count++;
  }
  
  cout << count << endl;
}