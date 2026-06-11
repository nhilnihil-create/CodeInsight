#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int m = max(a, max(b, c));
  
  if(a == m) a*= pow(2, k);
  else if(b == m) b *= pow(2, k);
  else c *= pow(2, k);
  cout << a + b + c << endl;
      
    
  return 0;
}