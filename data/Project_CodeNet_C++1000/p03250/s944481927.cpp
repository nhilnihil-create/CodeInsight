#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;cin>>a>>b>>c;
  d=max({a,b,c});
  if(d==a)d=a*10+b+c;
  else if(d==b)d=b*10+a+c;
  else d=c*10+a+b;
  cout<<d;
}