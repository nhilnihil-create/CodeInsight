#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7;

int main(){
  long long n, c;
  vector<long long> v;
  cin >> n;
  long long prev=-1;
  for(int i=0;i<n;i++){
    cin >> c;
    if(c!=prev){
      v.push_back(c);
      prev = c;
    }
  }
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  long long dp[200009];
  map<long long, long long> mp;
  dp[0] = 1;
  mp[v[0]] = 1;
  for(int i=1;i<v.size();i++){
    dp[i] = (mp[v[i]] + dp[i-1])%MOD;
    mp[v[i]] = (dp[i-1]+mp[v[i]])%MOD;
  }
  cout << dp[v.size()-1] << endl;
}

