#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)  for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using ull = unsigned long long;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum = pow(3,n);
  ll cnt = 1;
  rep(i,n){
    cin >> a.at(i);
    ll num = 0;
    if( ( a.at(i) - 1 )%2 != 0 ) num++;
    if( ( a.at(i) + 1 )%2 != 0 ) num++;
    if( a.at(i)%2 != 0 ) num++;
    cnt *= num;
  }
  
  cout << sum - cnt << endl;
  
  return 0;
}