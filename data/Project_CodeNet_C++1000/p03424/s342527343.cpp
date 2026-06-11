#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,p=0,w=0,g=0,y=0;
  cin>>n;
  char c[n];
  for(int i=0;i<n;i++){
    cin>>c[i];
    if(c[i]=='P'){
      ++p;
    }else if(c[i]=='W'){
      ++w;
    }else if(c[i]=='G'){
      ++g;
    }else if(c[i]=='Y'){
      ++y;
    }
  }
  int ans=0;
  if(p>=1){
    ++ans;
  }
  if(w>=1){
    ++ans;
  }
  if(g>=1){
    ++ans;
  }
  if(y>=1){
    ++ans;
  }
  if(ans==3){
    cout<<"Three"<<endl;
  }else if(ans==4){
    cout<<"Four"<<endl;
  }
  return 0;
}