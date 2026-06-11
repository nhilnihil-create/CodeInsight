#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(int a,int b)
{
  ll g=__gcd(a,b);
  return (a/g)*b;
}
int main()
{
  int n,m;
  cin>>n>>m;
  string s,t;
  cin>>s>>t;
  ll l=lcm(n,m);
  ll l2=lcm(l/n,l/m);
  if(s[0]!=t[0])
  {
    cout<<-1<<endl;
    return 0;
  }
  for(int i=1;i<=(l/l2);i++)
  {
    if(((i*l2)/(l/n))>=n || ((i*l2)/(l/m))>=m)break;
    if(s[(i*l2)/(l/n)]!=t[(i*l2)/(l/m)])
    {
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<l<<endl;
  return 0;
}
    
    