#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,s,c[101],t[101],mn=100000;
  cin>>n>>s;
  
  for(int i=0;i<n;i++){
    cin>>c[i]>>t[i];
  }
  for(int i=0;i<n;i++){
    if(t[i]<=s){
      mn=min(mn,c[i]);
    }
  }
  if(mn==100000){
    cout<<"TLE"<<endl;
  }
  else{
    cout<<mn<<endl;
  }
}
  