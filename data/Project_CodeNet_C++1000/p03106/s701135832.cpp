#include<bits/stdc++.h>
using namespace std;

int gcm(int x,int y)
{
  if(x%y==0)
  {
    return y;
  }
  return gcm(y,x%y);
}

int main()
{
  int a,b,k,x;
  x=0;
  cin>>a>>b>>k;
  vector<int> u;
  for(int i=1;i<=gcm(a,b);i++)
  {
    if(gcm(a,b)%i==0)
    {
      u.push_back(i);
      x++;
    }
  }
  cout<<u.at(x-k)<<endl;
}