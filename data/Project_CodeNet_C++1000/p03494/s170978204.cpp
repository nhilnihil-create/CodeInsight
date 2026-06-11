#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,y,i,ans=100;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x;
    y=0;
    while(x%2==0){
      y++;
      x/=2;
    }
    ans=min(ans,y);
  }
  cout<<ans<<endl;
}