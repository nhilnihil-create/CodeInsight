#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  ll n;
  cin >>n;
  ll ans=5;
  ll g=n;
  rep(i,5){
    ll r;
    cin >> r;
    chmin(g,r);
  }
  if(g!=n)ans+=(n+g-1)/g-1;
  cout << ans << endl;
}