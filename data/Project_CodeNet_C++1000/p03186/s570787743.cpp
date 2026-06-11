#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long a,b,c;
  cin >> a >> b >> c;

	if (a+b >= c)
    {
     cout << c + b << endl; 
    }
  else if (a+b < c)
  {
   cout <<  b + a+b + 1 << endl;
  }
}
