#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int m=max({a,b,c});
  int t=m;
  for(int i=1;i<=k;i++) m*=2;
  cout<<a+b+c+m-t;
}
