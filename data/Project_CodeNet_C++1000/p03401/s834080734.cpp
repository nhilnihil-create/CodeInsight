#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( ll i = 0;i < (ll) n;++i)

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> num(n);
  rep(i,n){
    cin >> a.at(i);
    num.at(i) = a.at(i);
  }
  sort(num.begin(),num.end());
  ll sum = 0;
  for(ll i=0;i<n;i++){
    if( i == 0 ) sum += abs(a.at(i));
    else if( i != n-1 ) sum += abs(a.at(i)-a.at(i-1));
    else sum += abs(a.at(i)-a.at(i-1)) + abs(a.at(i));
  }
  //cout << sum << endl;
  rep(i,n){
    if( i == 0 ){
      cout << sum - abs(a.at(i)) - abs(a.at(i)-a.at(i+1)) + abs(a.at(1)) << endl;
    }else if( i != n-1 ){
      cout << sum - abs(a.at(i-1)-a.at(i)) - abs(a.at(i)-a.at(i+1)) + abs(a.at(i-1)-a.at(i+1)) << endl;
    }else{
      cout << sum - abs(a.at(i-1)-a.at(i)) - abs(a.at(i)) + abs(a.at(i-1)) << endl;
    }
  }
  return 0;
}