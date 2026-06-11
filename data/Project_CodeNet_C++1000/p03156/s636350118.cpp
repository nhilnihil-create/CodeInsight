#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,a,b;cin>>n>>a>>b;
  vector<int> p(n);
  rep(i,n)cin>>p[i];
  int cnt1=0,cnt2=0,cnt3=0;
  rep(i,n){
    if(p[i]<=a)cnt1++;
    else if(a<p[i]&&p[i]<=b)cnt2++;
    else cnt3++;
  }
  int ans=min({cnt1,cnt2,cnt3});
  cout<<ans<<endl;
}