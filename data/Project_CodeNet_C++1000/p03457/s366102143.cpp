#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int t[n],x[n],y[n];
  rep(i,n) cin >> t[i] >> x[i] >> y[i];
  
  rep(i,n)
  {
    if(t[i] % 2 != (x[i] + y[i]) % 2) 
    {
      cout << "No" << endl;
      return 0;
    }
  }
  
  if(t[0] < x[0] + y[0])
  {
    cout << "No" << endl;
    return 0;
  }
  for(int i = 1; i < n; i++)
  {
    if( (t[i] - t[i-1]) < abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) ) 
    {
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
}