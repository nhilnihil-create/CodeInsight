#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


int main(){
  ll n;  cin >> n;
  string s; cin >> s;

  map<char, ll> key;
  for(ll i=0; i<n; i++){
    key[s[i]] += 1;
  }
  ll sum = 1;
  for(auto x: key){
    sum *= (x.second+1);
    sum %= MOD;
  }
  cout << sum-1<< endl;
}
