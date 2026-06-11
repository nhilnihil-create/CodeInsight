#include<bits/stdc++.h>
using namespace std;
#define int long

main(){
  int x,y;
  cin>>x>>y;
  if(x<y)cout<<x;
  else if(x%y!=0)cout<<x;
  else cout<<-1;
}