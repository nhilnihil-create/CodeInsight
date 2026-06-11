#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
  ll x,y;
  cin>>x>>y;
  ll count=0;
  for(ll i=x;i<=y;i=i*2)
  {
    
    
    
    if(i<=y)
      count++;
    else
      break;
  
  
}
  cout<<count<<endl;
}
