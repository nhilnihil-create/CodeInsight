#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,h,w;cin>>n>>h>>w;
  int ans=(n-h+1)*(n-w+1);
  cout<<ans<<endl;
}