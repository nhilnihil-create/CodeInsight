#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int ans=0;
  rep(i,n-1){
    if(a[i]==a[i+1]){
      ans++;
      a[i+1]=0;
    }
  }
  cout<<ans<<endl;
}