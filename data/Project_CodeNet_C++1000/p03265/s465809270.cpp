#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll a,b,c,d,e,f;
  cin>>a>>b>>c>>d;
  f = c - a;
  e = d - b;
  cout<<c-e<<" "<<d+f<<" "<<a-e<<" "<<b+f<<"\n";
  return 0;
}