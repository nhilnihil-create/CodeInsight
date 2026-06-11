#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n;
  string s;
  cin >> n >> s;
  vector<ll> v(26,0);
  rep(i,n)v[s[i]-'a']++;
  ll res = 1;
  rep(i,26)(res *= (v[i]+1))%= MOD;
  res = (res-1+MOD)%MOD;
  cout << res << endl;




  return 0;
}