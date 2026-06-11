#include<bits/stdc++.h>
using namespace std;
#define outc cout
#define int long long
signed main(){
  int a;
  int b=0,c=1,d,e=0,f=0,l=0;
  cin>>a>>b>>c;
  d=max(b,c)-min(b,c);
  if(d%2==0) cout<<"Alice";
  else cout<<"Borys";
  cout<<"\n";}