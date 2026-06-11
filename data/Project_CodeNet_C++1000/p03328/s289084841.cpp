#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

  int a,b;
  cin >> a >> b;

  for(int i=1; i<=998; i++)
  {
      int w = (i*(i+1))/2;
      int e = ((i+1)*(i+1+1))/2;
      if(a <= w && b <= e && (a+b)!= (w+e) && (w-a)==(e-b) )
      {
         // cout << i << " " << i+1 << endl;
          int sum = (w-a) ;
          cout << sum << endl;
          return 0;
      }

  }

    }
