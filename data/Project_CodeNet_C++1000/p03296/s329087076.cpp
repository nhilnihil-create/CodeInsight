#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  int c;cin>>c;
  int result=0;
  int t;

  rep(i,n-1){
    cin>>t;
    if(t==c){
      result++;
      c=-1;
    }else{
      c=t;
    }
  }

  cout<<result;

  return 0;
}