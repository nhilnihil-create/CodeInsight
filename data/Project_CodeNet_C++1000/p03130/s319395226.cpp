#include <bits/stdc++.h>
using namespace std;
int main(){
  int i;
  int a[6];
  for(i=0;i<6;++i){
    cin>>a[i];
  }
  for(i=0;i<6;++i){
    a[i]=a[i]-1;
  }
  int c[4]={0,0,0,0};
  for(i=0;i<6;++i){
    if(a[i]==0){
      c[0]++;
    }
    else if(a[i]==1){
      c[1]++;
    }
    else if(a[i]==2){
      c[2]++;
    }
    else{
      c[3]++;
    }
  }
  int f=0,g=0;
  for(i=0;i<4;++i){
    if(c[i]==1){
      f++;
    }
    if(c[i]==2){
      g++;
    }
  }
  if(f==2&&g==2){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
  return 0;
}
