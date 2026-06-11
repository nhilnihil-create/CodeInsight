#include<bits/stdc++.h>
using namespace std;
int main()
{
  int d,i,c,a[10000];
  int sum=0;
  cin>>d;
  for(i=0;i<d;i++)
  {
    cin>>a[i];
  }
  sort(a,a+d);
  for(i=0;i<d;i++)
  {
    
   
    if(i==d-1)
    {
      int z=a[i];
      c=(int)z/2;
      sum=sum+c;
      break;
    }
    sum=sum+a[i];
  }

  cout<<sum<<endl;
  return 0;
}
