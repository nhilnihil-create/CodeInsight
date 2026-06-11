#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N, N_pl, sum;
  cin >> N;
  N_pl = N;
  sum = 0;

  while ( N_pl >= 1)
  {
    sum = sum + N_pl % 10;
    
    N_pl /= 10;
  }


  if (N % sum == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}