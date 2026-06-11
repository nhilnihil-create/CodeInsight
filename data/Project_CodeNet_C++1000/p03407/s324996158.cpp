#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int a,b,c;
  string ans="Yes";
  cin >> a>>b>>c;
  if(a+b<c)ans="No";  
  cout << ans << endl;
      return 0;
}
