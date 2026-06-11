#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, x, y ;
  cin >> a >> b >> c >> x >> y ;

  int answer = 1000000000 ;
  int max_i = max(x, y) * 2 ;
  for(int i = 0 ; i <= max_i ; i++)
  {
    if(i == 0)
    {
      answer = min(answer, x * a + y * b) ;
    }
    else if(i % 2 == 0)
    {
      int j = x - i / 2 ;
      int k = y - i / 2 ;
      if(j < 0)
      {
        j = 0;
      }
      if(k < 0)
      {
        k = 0 ;
      }
      answer = min(answer, ( j * a + k * b + c * i )) ;
    }
  }

  cout << answer << endl ;
}
