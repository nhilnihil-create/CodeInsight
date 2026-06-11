#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,h,w;cin>>n>>h>>w;
  int cnt=0;
  rep(i,n){
    int a,b;cin>>a>>b;
    if(a>=h&&b>=w)cnt++;
  }
  cout<<cnt<<endl;
}