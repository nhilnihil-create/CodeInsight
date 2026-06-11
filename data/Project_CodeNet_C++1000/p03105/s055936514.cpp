#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  for(int i=1;i<=c;i++) {
    if(b>=a*i){
      ans++;
    }
    else{
      break;
    }
    
  }
  
  cout<<ans<<endl;
  return 0;
}