#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int ans=0;
  rep(i,n){
    int a;cin>>a;a--;
    ans+=a;
  }
  cout<<ans<<endl;
}