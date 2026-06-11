#include<bits/stdc++.h>
using namespace std;
int i,j,n,m=1001,k,l,t,b,a,c;
int main()
{
  for(cin>>n>>t;i<n;i++){
    cin>>a>>b;
    if(b<=t)m=min(m,a);
  }
  if(m==1001)return cout<<"TLE",0;
  cout<<m;
}