#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll K; cin >> K;
  vector<ll> a(K);
  for(ll i = 0; i < K; i++) cin >> a[K - i - 1];
  
  ll L = 2, R = 2;
  for(ll i = 0; i < K; i++){
    ll qer = a[i];
    L = ((L-1) / qer) * qer + qer;
    if(L > R) {cout << -1 << endl; return 0;}
    R = (R / qer) * qer + qer - 1;
  }
  cout << L << ' ' << R << endl;
}