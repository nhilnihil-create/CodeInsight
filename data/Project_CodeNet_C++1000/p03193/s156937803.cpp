#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long a,b,x,i,c=0,n,h,w;
    cin>>n>>h>>w;
    for(i=1;i<=n;i++)
    {
      cin>>a>>b;
      if(a>=h&&b>=w) c++;
    }
    cout<<c<<endl;


  return 0;
}
