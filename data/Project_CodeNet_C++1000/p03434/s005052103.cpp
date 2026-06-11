#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int alice=0,bob=0;
  sort(a.begin(),a.end(),greater<int>());
  rep(i,n){
    if(i%2==0)alice+=a[i];
    else bob+=a[i];
  }
  cout<<alice-bob<<endl;
  return 0;
  
}