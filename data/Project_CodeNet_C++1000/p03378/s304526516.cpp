#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,m,x;
  cin>>n>>m>>x;
  vector<int> a(m);
  int above=0;
  int under=0;
  rep(i,m){
    cin>>a[i];
    if(a[i]<x){
      under++;
    }else{
      above++;
    }
  }
  cout<<min(above,under)<<endl;
}