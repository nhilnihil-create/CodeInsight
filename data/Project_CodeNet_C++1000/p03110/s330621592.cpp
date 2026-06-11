#include<iostream>
#include<string>

using namespace std;

int main()
{
  int n;
  cin>>n;
  
  const int x=n;
  
  string s[x];
  double m[x];
  
  for(int i=0;i<x;i++)
  {
    
    cin>>m[i];
    cin>>s[i];
  }
  
  double ans;
  
  for(int i=0;i<x;i++)
  {
    if(s[i]=="BTC")
    {
      ans+=(m[i]*380000);
    }
    else
    {
      ans+=m[i];
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
  
  