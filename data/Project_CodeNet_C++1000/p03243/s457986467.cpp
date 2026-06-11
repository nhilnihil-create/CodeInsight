#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,d,x,y;
int main()
{
  cin>>x;n=x/100;y=100*n+10*n+n;
  if(x<=y)return cout<<y,0;
  else return n++,cout<<100*n+10*n+n,0;
}