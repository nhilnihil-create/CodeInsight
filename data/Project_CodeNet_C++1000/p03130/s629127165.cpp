#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a[4],b[4],c[5]={};
  int cun=0,cum=0;
  for(int i=1;i<=3;i++){
    cin>>a[i]>>b[i];
    c[a[i]]++;
    c[b[i]]++;
  }
  for(int i=1;i<=4;i++){
    if(c[i]==2){
      cun++;
    }else if(c[i]==1){
      cum++;
    }
  }
  if(cun==2 && cum==2){
    cout<<"YES\n";
  }else{
    cout<<"NO\n";
  }
  return 0;
}