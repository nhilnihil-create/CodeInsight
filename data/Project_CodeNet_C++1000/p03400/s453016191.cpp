#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,d,x;cin>>n>>d>>x;
  int cnt=x;
  d--;
  rep(i,n){
    int a;cin>>a;
    
    cnt+=d/a+1;
  }
  cout<<cnt<<endl;
}