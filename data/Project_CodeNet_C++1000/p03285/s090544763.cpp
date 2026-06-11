#include<bits/stdc++.h>
using namespace std;
void solve(int n){
  if(n%4==0){
    cout<<"Yes"<<endl;
    return;
  }
  if(n%7==0){
    cout<<"Yes"<<endl;
    return;
  }
  for(int i=7;i<n;i=i+7){
    if((n-i)%4==0){
      cout<<"Yes"<<endl;
      return;
    }
  }
  cout<<"No"<<endl;
  return;
}
int main(){
  int n;
  cin>>n;
  solve(n);
  return 0;
}