#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  int c11,c12,c13,c21,c22,c23,c31,c32,c33;
  cin>>c11>>c12>>c13>>c21>>c22>>c23>>c31>>c32>>c33;
  string ans;
  
  if(c11-c12!=c21-c22){ans="No";}
  else if(c31-c32!=c21-c22){ans="No";}
  else if(c11-c13!=c21-c23){ans="No";}
  else if(c11-c13!=c31-c33){ans="No";}
  else if(c11-c21!=c12-c22){ans="No";}
  else if(c11-c21!=c13-c23){ans="No";}
  else if(c11-c31!=c12-c32){ans="No";}
  else if(c11-c31!=c13-c33){ans="No";}
  else{ans="Yes";}
  
  cout<<ans;
}