#include<bits/stdc++.h>
using namespace std;

int z(int x)
{
  if(x>=0)
    return x;
  else
    return x*-1;
}

int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(z(a-c)<=d)
    cout<<"Yes"<<endl;
  else if((z(a-b)<=d)&&(z(b-c)<=d))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}