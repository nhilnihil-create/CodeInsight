//by The_One_Solver
#include<bits/stdc++.h>
using namespace std;
long long  n,m,c,arr[10001],a,b,d;
int main()
{
  for(int i=0;i<3;i++)cin>>arr[i];
  cin>>m;
  c=m%2;
  a=arr[1]+arr[2];
  b=arr[0]+arr[2];
  if(c)cout<<a-b;
  else cout<<arr[0]-arr[1];
    return 0;
}
