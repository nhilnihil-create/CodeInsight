#include<bits/stdc++.h>
using namespace std;

int main()
{
 int a,b;
  cin>>a>>b;
  string nish;
  cin>>nish;
  for(int i=1;i<=a;i++)
  {
    if(i==b)
    {
      nish[i-1]=tolower(nish[i-1]);
    }
  }
  
  cout<<nish<<endl;
  
return 0;
}