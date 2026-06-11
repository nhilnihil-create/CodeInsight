#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,c=0;
  cin>>a>>b;
  for(ll i=a;i<=b;i++)
  {
      string s= to_string(i);
      if(s[0]==s[4]&&s[1]==s[3])
      {
          c++;
      }
  }
  cout<<c<<endl;
   return 0;
}
