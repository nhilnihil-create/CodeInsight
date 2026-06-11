#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int ans=0;
  rep(i,n)for(int j=i+1;j<n;j++){
    ans=max(ans,abs(a[i]-a[j]));
  }
  cout<<ans<<endl;
}