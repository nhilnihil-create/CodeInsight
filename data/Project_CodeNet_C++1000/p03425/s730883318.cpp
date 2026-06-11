#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<string> s(n);
  rep(i,n)cin>>s[i];
  string t="MARCH";
  vector<int> cnt(5);
  rep(i,n){
    rep(j,5){
      if(t[j]==s[i][0])cnt[j]++;
    }
  }
  ll ans=0;
  rep(i,5)for(int j=i+1;j<5;j++)for(int k=j+1;k<5;k++){
    ans+=(ll)cnt[i]*cnt[j]*cnt[k];
  }
  cout<<ans<<endl;
}