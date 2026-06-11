#include<iostream>
using namespace std;
int main()
{
  int a,b,c,ans=0;
  cin>>a>>b>>c;
  for(int i=0;i<c;i++)
  {
    if(b-a>=0)
    {
      ans++;
      b-=a;
    }
    else break;
  }
  cout<<ans;
}