#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n)cin>>p[i];
  sort(p.begin(),p.end());
  int ans=0;
  rep(i,n){
    if(i==n-1)p[i]/=2;
    ans+=p[i];
  }
  cout<<ans<<endl;
}