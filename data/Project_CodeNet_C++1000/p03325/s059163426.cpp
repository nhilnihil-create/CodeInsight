#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z,ans=0;
  cin>>z;
  for(x=0;x<z;x++){
    cin>>y;
    while(y%2==0){
      ans++;
      y/=2;
    }
  }
  cout<<ans<<endl;
}