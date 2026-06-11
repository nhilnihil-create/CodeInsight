#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,k,c,sw,ans;
  sw=0;
  
  cin >> a >> b >> k;
  c=gcd(a,b);
  ans=c;
  while(sw<k)
  {
  if(c%ans==0) sw++;
  ans--;
  }
  cout << ans+1;
return 0;}