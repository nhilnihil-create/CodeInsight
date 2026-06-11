#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,y,a,b;
  cin>>x>>y>>a>>b;
  int s=a-x;
  int t=b-y;
  int c=a-t;
  int d=b+s;
  int e=c-s;
  int f=d-t;
  cout<<c<<' '<<d<<' '<<e<<' '<<f;
}