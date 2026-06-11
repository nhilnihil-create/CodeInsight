#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

ll gcd(ll a, ll b);

int main(){
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> migi(n);
  vector<ll> hidari(n);
  migi.at(n-1)= a.at(n-1);
  hidari.at(0)= a.at(0);

  rep(i, n-1){
    hidari.at(i+1) = gcd(a.at(i+1), hidari.at(i));
  }

  rep(i, n-1){
    migi.at(n-i-2) = gcd(a.at(n-i-2), migi.at(n-i-1));
  }

  //rep(i,n) cout << hidari.at(i) << endl;

  ll max = 0;
  rep(i,n){
    ll left, right;
    ll now;
    if(i==0) now = migi.at(1);
    else if(i==n-1) now = hidari.at(n-2);
    else now = gcd(migi.at(i+1), hidari.at(i-1));
    if(now>=max) max = now;
  }

  cout << max;
}

ll gcd(ll a, ll b){
  if(a%b==0) return b;
  else return gcd(b, a%b);
}
