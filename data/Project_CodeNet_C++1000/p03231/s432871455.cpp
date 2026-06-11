#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){
  return (b!=0 ? gcd(b,a%b):a);
}

int main(){
  ll n,m;
  cin >> n >> m;
  string s,t;
  cin >> s;
  cin >> t;
  ll l = n/gcd(n,m)*m;
  map<ll,char> mp;
  for(int i=0;i<n;i++){
    mp[l/n*i] = s[i];
  }
  for(int i=0;i<m;i++){
    if(mp.count(l/m*i)>0 && mp[l/m*i]!=t[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << endl;
  return 0;
}
