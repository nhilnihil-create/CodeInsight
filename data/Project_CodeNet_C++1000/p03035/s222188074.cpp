#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int a,b,ans; 
  cin>>a>>b;
  if(a<=5)ans=0;
  else if(a<=12)ans=b/2;
  else{ans=b;}
    
  cout<<ans;
}