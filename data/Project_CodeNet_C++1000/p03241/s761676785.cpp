#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


vector<ll> divisor(ll n){
  vector<ll> res;
  for (ll i(1);i*i<=n;i++){
    if (n%i==0){
      res.push_back(i);
      if (i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

int main(){
  ll N,M;
  cin>>N>>M;
  vector<ll> yakusuu = divisor(M);
  sort(yakusuu.begin(),yakusuu.end());
  for(int i(0);i<int(yakusuu.size());i++){
    if(N<=yakusuu[i]) {
      cout << M/yakusuu[i] << endl;
      return 0;
    }
  }
  return 0;
}
