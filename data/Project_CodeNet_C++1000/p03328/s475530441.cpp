#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  int a,b;
  int n=0,res=0;

  cin>>a>>b;

  n=b-a;

  for(int i=1; i<=n; i++)
  {
    res+=i;
  }
  cout<<res-b<<endl;
}
