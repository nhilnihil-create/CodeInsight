#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n; cin>>n;
  vector<ll> num(n);
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  if(num[0]!=0){
    cout<<-1<<endl;
    return 0;
  }ll ans=0;
  if(n==2){
    if(num[1]==0){
      cout<<0<<endl;
      return 0;
    }else if(num[1]==1){
      cout<<1<<endl;
      return 0;
    }else {
      cout<<-1<<endl;
      return 0;
    }
  }
  for(int i=1;i<n-1;i++){
    if(num[i]>i){
      cout<<-1<<endl;
      return 0;
    }
    if(num[i]<num[i+1]){
      if(num[i+1]-num[i]!=1){
        cout<<-1<<endl;
        return 0;
      }else if(i+1==n-1){
        ans+=num[i+1];
      }
    }else{
      ans+=num[i];
      if(i+1==n-1){
        ans+=num[i+1];
      }
    }
  }
  cout<<ans<<endl;
}