#include <bits/stdc++.h>
using namespace std;
bool prime(int a){
  if(a==1){
    return false;
  }
  for(int i=2;i*i<=a;i++){
    if(a%i==0){
      return false;
    }
  }
  return true;
}
int main(){
  int Q,lm=0;
  cin>>Q;
  unordered_map<int,int> mp;
  for(int i=1;i<=100000;i++){
    mp[i]=mp[i-1];
    if(i%2==1 && prime(i) && prime((i+1)/2)){
      //cout<<i<<" "<<(i+1)/2<<endl;
      mp[i]++;
      lm++;
    }
  }
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;
    cout<<mp[b]-mp[a-1]<<endl;
  }
}