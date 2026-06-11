#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  double cnt=0;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
    cnt+=a[i];
  }
  cnt/=n;
  int ans;
  double cnt1=1e9;
  rep(i,n){
    if(abs(cnt-a[i])<cnt1){
      cnt1=abs(cnt-a[i]);
      ans=i;
    }
  }
  cout<<ans<<endl;
}