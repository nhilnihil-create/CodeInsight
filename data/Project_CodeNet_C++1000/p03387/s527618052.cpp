#include <bits/stdc++.h>
using namespace std;
long long n,i,j,a,b,c,d;
int main(){
  cin>>a>>b>>c;
  long long m=max(a,max(b,c));
  m*=3;
  d=a+b+c;
  if(m%2==d%2)cout<<(m-d)/2;
  else cout<<(m-d+3)/2;
}