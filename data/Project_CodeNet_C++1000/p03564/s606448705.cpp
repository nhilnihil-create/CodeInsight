#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
  int a,b;
  cin>>a>>b;
  int pow=1;
  int ans=0;
  while(pow<=b && a)
  {
    pow*=2;
    ans++;
    a--;
  }
  if(a)
  {
    cout<<pow+a*b<<endl;
  }
  else
  cout<<pow<<endl;

  
}