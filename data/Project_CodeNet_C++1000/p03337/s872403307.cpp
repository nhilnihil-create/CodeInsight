#include <bits/stdc++.h>
using namespace std;

main(){
  int a,b,c,d,e,f,g,h;
  cin>>a>>b;
  c=a+b;
  d=a-b;
  e=a*b;
  f=max(c,d);
  g=max(d,e);
  h=max(f,g);
  cout<<h<<endl;
}