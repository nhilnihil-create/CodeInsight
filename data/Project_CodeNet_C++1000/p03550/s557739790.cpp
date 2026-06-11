#include<bits/stdc++.h>
using namespace std;
#define int long long int   
int32_t main()
{
  int x,y,z;
  cin>>x>>y>>z;
  int a[x];
  for(int i=0;i<x;i++)
  cin>>a[i];
  if(x==1)
  cout<<abs(z-a[0])<<endl;else
  cout<<max(abs(a[x-1]-z),abs(a[x-1]-a[x-2]))<<endl;
}