#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
  cin>>hex>>x>>y;
  if(x>y)cout<<'>';
  else if(x==y)cout<<'=';
  else cout<<'<';
}