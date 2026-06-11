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
  cin >> n;
  vector<ll> s(n+1,0);
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  rep(i,n)s[i+1] = s[i]+v[i];
  map<ll,ll> mp;
  rep(i,n+1)mp[s[i]]++;
  ll res = 0;
  for(auto iter = mp.begin();iter != mp.end();iter++)res += (*iter).second*((*iter).second-1)/2;
  cout << res << endl;




  return 0;
}