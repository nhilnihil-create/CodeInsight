#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,a[105],d,maxi=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i!=j)
      {
        int d=abs(a[i]-a[j]);
        maxi=max(maxi,d);
      }
    }
  }
  cout<<maxi<<endl;
}
