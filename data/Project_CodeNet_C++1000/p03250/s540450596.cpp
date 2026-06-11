#include "bits/stdc++.h"
using namespace std;

int main()
{
  int a,b,c,p,q,r;
  cin>>a>>b>>c;
  p=a*10+b+c;
  q=b*10+c+a;
  r=c*10+a+b;
  cout<<max(max(p,q),r)<<endl;
}