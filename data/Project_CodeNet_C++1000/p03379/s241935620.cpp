#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;
//階乗できるよ
ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n; cin >> n;
  vector<ll> x(n); rep(i,n) cin >> x.at(i);
  vector<ll> xxx(n); rep(i,n) xxx.at(i) = x.at(i);
  sort(xxx.begin(),xxx.end());

  ll middle_small = xxx.at(n/2 - 1), middle_big = xxx.at(n/2);
  if(middle_big == middle_small) {
    rep(i,n) {
      cout << middle_big << endl;
    }
    return 0;
  }
  else {
    rep(i,n) {
      if(x.at(i) <= middle_small) {
        cout << middle_big << endl;
      }
      else {
        cout << middle_small << endl;
      }
    }
  }

  
  
}

