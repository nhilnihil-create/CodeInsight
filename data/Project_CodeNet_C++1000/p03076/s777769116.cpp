#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  int a,b,c,d,e,A,B,C,D,E;
  cin>>a>>b>>c>>d>>e;
  int sum=a+b+c+d+e;
  rep(i,65){
    if(10*i<a && a<=10*(i+1)){ A=10*(i+1)-a;}
    if(10*i<b && b<=10*(i+1)){ B=10*(i+1)-b;}
    if(10*i<c && c<=10*(i+1)){ C=10*(i+1)-c;}
    if(10*i<d && d<=10*(i+1)){ D=10*(i+1)-d;}
    if(10*i<e && e<=10*(i+1)){ E=10*(i+1)-e;}
  }
  int m=max(max(max(A,B),max(C,D)),E);
  cout<<sum+A+B+C+D+E-m<<endl;
  
  }