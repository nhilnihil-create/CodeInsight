#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,t,a;cin>>n>>t>>a;
  double ans=1e9;
  int cnt;
  for(int i=1;i<=n;i++){
    int h;cin>>h;
    if(abs(a-(t-h*0.006))<ans){
      ans=abs(a-(t-h*0.006));
      cnt=i;
    }
  }
    cout<<cnt<<endl;
  }