#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
  cin >>n;
  
  vector<long int> a(n);
  long int ans;
  cin >>a.at(0);
  ans=a.at(0);
  for(int i=1;i<n;++i)
  {
  cin >> a.at(i); 
  ans=gcd(ans,a.at(i));
  }
  cout << ans;
return 0;
}