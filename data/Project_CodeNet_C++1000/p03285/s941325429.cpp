#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  rep(i,30)rep(j,20){
    if(4*i+7*j==n){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}