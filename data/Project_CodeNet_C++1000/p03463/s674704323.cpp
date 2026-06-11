#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, ali, bor;
  string ans;
  cin >> n;
  cin >> ali;
  cin >> bor;
  ans = "Alice";
  a =((bor-1)-ali)%2;
  if(a == 0) ans = "Borys";
  cout << ans << endl;
  return 0;
}