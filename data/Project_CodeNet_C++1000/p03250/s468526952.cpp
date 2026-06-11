#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  ans = 10*a+b+c;
  if(10*b+a+c>ans)
    ans=10*b+a+c;
  if(10*c+a+b>ans)
    ans=10*c+a+b;
  cout<<ans<<endl;
}