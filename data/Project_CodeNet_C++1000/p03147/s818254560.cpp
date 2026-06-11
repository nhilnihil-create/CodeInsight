#include<bits/stdc++.h>
using namespace std;
void f(int l,int r,vector<int> &h,int &t,int &ans){
  int i,mi=100;
  for(i=l;i<=r;i++){
    if(h.at(i)<mi){
      mi=h.at(i);
      if(mi==0) break;
    }
  }
  if(mi==0){
    if(l<=i-1) f(l,i-1,h,t,ans);
    if(i+1<=r) f(i+1,r,h,t,ans);
  }
  else{
    ans+=mi;
    t-=mi*(r-l+1);
    if(t==0) return;
    else{
      for(i=l;i<=r;i++) h.at(i)-=mi;
      f(l,r,h,t,ans);
    }
  }
}
int main(){
  int n,i,t=0,ans=0;
  cin>>n;
  vector<int> h(n);
  for(i=0;i<n;i++){
    cin>>h.at(i);
    t+=h.at(i);
  }
  f(0,n-1,h,t,ans);
  cout<<ans<<endl;
}