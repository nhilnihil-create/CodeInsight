#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> ma;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    ma[a]++;
  }
  
  ll sum = 0;
  for(auto it:ma){
   ll num = it.first;
   if(num<=it.second){
     sum += it.second-num;
   }else{
     sum += it.second;
   }
  
  }
  
  cout << sum << endl;
  

  return 0;
}