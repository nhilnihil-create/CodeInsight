#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a,b,c,d,x=0,y=200;
int main()
{
  cin>>n>>m>>a>>b;
  a+=100;b+=100;
  for(;i<n;i++)cin>>c,x=max(x,c+100);
  for(i=0;i<m;i++)cin>>d,y=min(y,d+100);
  if(min(y,b)-max(x,a)>0)cout<<"No War";
  else cout<<"War";
}