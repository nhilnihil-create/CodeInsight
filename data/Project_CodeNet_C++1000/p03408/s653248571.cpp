#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n;
  map<string,int> mp;
  rep(i,n){
    string s;
    cin >> s;
    mp[s]++;
  }
  cin >> m;
  rep(i,m){
    string s;
    cin >> s;
    mp[s]--;
  }
  int ans=0;
  for(auto p: mp){
    ans=max(max(0,ans),mp[p.first]);
  }
  cout << ans;
}
  
    