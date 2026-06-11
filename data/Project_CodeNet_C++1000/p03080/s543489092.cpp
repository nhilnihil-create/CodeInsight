#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  char t;
  int rc=0;
  rep(i,n){
    cin>>t;
    if(t=='R')rc++;
    else rc--;
  }

  if(rc>0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}