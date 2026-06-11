#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
  int x;
  cin>>x;
  vector<bool> c(x+1,0);
  c[1]=1;
  for(int i=2;i<x;i++)
  {
    int temp=i*i;
    while(temp<=x)
    {
      c[temp]=1;
      temp*=i;
    }
  }
 
  for(int i=x;i>=1;i--)
  if(c[i])
  {
    cout<<i<<endl;
    return 0;
  }
}	