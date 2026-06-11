#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<ll> vec(5);
  string t="MARCH";
  rep(i,n){
    string s;cin>>s;
    rep(j,5){
      if(s[0]==t[j])vec[j]++;
    }
  }
  ll ans=0;
  rep(i,3)for(int j=i+1;j<4;j++)for(int k=j+1;k<5;k++){
    ans+=vec[i]*vec[j]*vec[k];
  }
  cout<<ans<<endl;
}