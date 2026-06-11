#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

const int MOD = 1e9+7;

int main(){
  int n;
  string s;
  cin>>n>>s;
  map<char,int> mp;
  rep(i,n){
    mp[s[i]]++;
  }
  ll ans=1;
  for(auto x : mp){
    ans*=(x.second+1);
    ans%=MOD;
  }
  ans--;
  cout<<ans<<endl;
}
