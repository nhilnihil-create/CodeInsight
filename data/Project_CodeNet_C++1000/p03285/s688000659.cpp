#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  string ans="No";
  if(n%4==0||n%7==0) cout<<"Yes"<<endl;
  else{
    while(n>0){
      if(n%4==0){
        ans="Yes";
      }
      n-=7;
    }
    cout<<ans<<endl;
  }
}